#include "db.h"

namespace FHdb {

DataBase::DataBase() :
  db_(std::make_shared<SkipList<Slice, Slice>>()),
  result_(nullptr), 
  error_(0) {
  testing_ = true;
  command_dict_["set"] = std::bind(&DataBase::Set, this);
  command_dict_["del"] = std::bind(&DataBase::Del, this);
  command_dict_["clear"] = std::bind(&DataBase::Clear, this);
  command_dict_["get"] = std::bind(&DataBase::Get, this);
  command_dict_["show"] = std::bind(&DataBase::Show, this);

  safe_command_["set"] = false;
  safe_command_["del"] = false;
  safe_command_["clear"] = false;
  safe_command_["get"] = true;
  safe_command_["show"] = true;
}

void DataBase::GetWord(size_t& pos, const std::string& str, std::string& temp) {
  temp = "";
  while (pos < str.size() && str[pos] == ' ') {
    pos++;
  }
  while (pos < str.size() && str[pos] != ' ') {
    temp += str[pos];
    pos++;
  }
}

int DataBase::ParseTheCommand(const std::string& command_line) {
  error_ = 0;
  command_ = "";
  message_ = "";
  dict_.clear();
  keys_.clear();
  size_t pos = 0;
  std::string temp_str;

  GetWord(pos, command_line, temp_str);
  command_ = temp_str;
  while (true) {
    GetWord(pos, command_line, temp_str);
    if (temp_str == "") {
      break;
    }
    keys_.push_back(Slice(temp_str));
  }
  
  for (char &v : command_) {
    if (std::isupper(v)) {
      v += 32;
    }
  }
  
  if (!persistencing_) {
    // LOG << "command_line: " << command_line;
    LOG << "command: " << command_;
    std::string key_str;
    for (auto && key : keys_) {
      key_str += key.ToString() + " ";
    }
    LOG << "key: " + key_str;
  }

  if (command_dict_.count(command_)) {
    command_dict_[command_]();
    assert(safe_command_.count(command_));
    if (!testing_ && !persistencing_ && !safe_command_[command_]) {
      std::string sql = command_;
      for (const auto& key : keys_) {
        sql += ' ' + key.ToString();
      }
      AOF << sql;
    }
  } else if (command_ == "q") {
    error_ = 2;
  } else {
    error_ = 1;
  }
  AddMessagePre();
  return error_;
}

void DataBase::AddMessagePre() {
  std::string prefix;
  switch (error_) {
    case 0: 
      prefix = "OK";
      break;
    case 1: 
      prefix = "command error";
      break;
    case 2: 
      prefix = "quit";
      break;
    case 3: 
      prefix = "key conflict";
      break;
    case 4: 
      prefix = "args error";
      break;
    default:
      prefix = "wrong error!!!";
  }
  if (!persistencing_) {
    LOG << "error: " << error_;
    LOG << prefix;
    if (message_.length()) {
      LOG << message_;
    }
  }

  if (message_.size()) {
    message_ = '\n' + message_;
  }
  message_ = prefix + message_;
}

void DataBase::Set() {
  if (keys_.size() == 0 || keys_.size() & 1) {
    error_ = 4;
    return ;
  }
  std::vector<bool> success = db_->Insert(keys_);
  assert(success.size() * 2 == keys_.size());

#ifdef CHECK_ON
  assert(db_->show().size() == ALIVE_NODE);
#endif

  for (size_t i = 0; i < success.size(); ++i) {
    if (success[i] == false) {
      error_ = 3;
      message_ += '(' + keys_[i * 2].ToString() + ','
                + keys_[i * 2 + 1].ToString() + ") ";
    }
  }
  return ;
}

void DataBase::Show() {
  if (keys_.size()) {
    error_ = 4;
    return ;
  }
  std::vector<std::shared_ptr<Node<Key, Value>>> nodes = db_->show();

  // check memory
#ifdef CHECK_ON
  assert(db_->show().size() == ALIVE_NODE);
#endif
  for (const auto& node : nodes) {
    Slice k(node->key_.ToString());
    Slice v(node->value_.ToString());
    assert(dict_.count(k) == 0);
    dict_[k] = v;
  }

  message_ += "[size: " + std::to_string(nodes.size()) + "]  ";
  for (auto node : nodes) {
    Node<Key, Value> no(node->key_, node->value_, node->level_);
    if (db_->try_compress()) {
      no.key_.UnCompress();
    }
    message_ += "(" + no.key_.ToString() + ',' + no.value_.ToString() + ") ";
  }
  return ;
}

void DataBase::Del() {
  if (keys_.size() == 0) {
    error_ = 4;
    return ;
  }
  db_->Delete(keys_);
  return ;
}

void DataBase::Clear() {
  if (keys_.size()) {
    error_ = 4;
    return ;
  }
  db_->Clear();
#ifdef CHECK_ON
  assert(db_->show().size() == ALIVE_NODE);
  assert(ALIVE_NODE == 0);
#endif
  error_ = 0;
  return ;
}

void DataBase::Get() {
  if (keys_.size() == 0) {
    error_ = 4;
    return ;
  }
#ifdef CHECK_ON
  assert(db_->show().size() == ALIVE_NODE);
#endif
  auto nodes = std::move(db_->Find(keys_));
  message_ = '(';
  for (const auto& node : nodes) {
    if (node == nullptr) {
      message_ += "null,";
    } else {
      message_ += node->value_.ToString() + ',';
    }
  }
  message_.back() = ')';
  return ;
}

void DataBase::Persistencing() {
  LOG << "==========start persistencing==========";
  persistencing_ = true;
  std::ifstream fin("aof_log");
  if (!fin.is_open()) {
    puts("open aof file fail");
  } else {
    std::string sql;
    while (std::getline(fin, sql)) {
      ParseTheCommand(sql);
    }
  }
  fin.close();
  ParseTheCommand("show");
  LOG << message_;
  LOG << "==========end persistencing==========";
  persistencing_ = false;
}

}

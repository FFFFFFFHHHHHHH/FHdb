#pragma once
#include "../skiplist/skiplist.h"
#include "../log/Logging.h"
#include "../util/util.h"
#include <map>
#include <functional>
#include <memory>

namespace FHdb {

class DataBase {
public:

  ~DataBase() = default;

  DataBase();

  static std::shared_ptr<DataBase> single() {
    static std::shared_ptr<DataBase> single_ptr = std::make_shared<DataBase>();
    return single_ptr;
  }

  void Set();

  void Del();

  void Clear();

  void Get();

  void Show();

  int ParseTheCommand(const std::string& command);

  std::string CommandToString() {
    std::string res = command_;
    for (const auto& key : keys_) {
      res += " " + key.ToString();
    }
    return res;
  }

  std::string message() const {
    return message_;
  }

  int error() const {
    return error_;
  }

private:

  inline void GetWord(size_t& pos, const std::string& str, std::string& temp);

  void AddMessagePre();

  typedef Slice Key;
  typedef Slice Value;

  std::shared_ptr<SkipList<Key, Value>> db_;
  std::shared_ptr<Slice> result_ = nullptr;

  std::string command_;
  std::vector<Key> keys_;

  std::string message_;
  int error_;
  // 0 OK
  // 1 command error
  // 2 quit
  // 3 key conflict
  // 4 args error

  std::map<std::string, std::function<void(void)>> command_dict_;

  constexpr static const char* LogPath_ = "db_log";
  constexpr static const char* AofPath_ = "aof_log";

};

}

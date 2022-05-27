#include "test.h"
#include "../log/Logging.h"
#include "../db/db.h"
#include <iostream>

extern int use_log;
namespace FHdb {

// test memory
// int cnt_delete;
// int cnt_new;

#define ERROR do{                   \
  std::cout << "error!  " << __LINE__;    \
  success = 0;                      \
} while(0);                         \

std::string test_skiplist_int() {
  bool success = true;
  SkipList<int, int> sk;

  for (int i = 0; i <= 10000; i++) {
     sk.Insert(i, i);
  }

  for (int i = 0; i <= 10000; i++) {
    auto ptr = sk.Find(i);
    if (!ptr) ERROR
    else if (ptr->value_ != i) ERROR
  }

  sk.Clear();
  assert(ALIVE_NODE_INT == 0); // test Clear
  assert(sk.Empty() == true); // test Empty

  srand(time(0));
  int rnd = rand();
  for (int i = 0; i <= 10000; i++) {
    sk.Insert(i, i + rnd);
  }

  for (int i = 0; i <= 10000; i++) {
    auto ptr = sk.Find(i);
    if (!ptr) ERROR
    else if (ptr->value_ != i + rnd) ERROR
  }
  sk.Clear();
  assert(ALIVE_NODE_INT == 0); // test Clear
  assert(sk.Empty() == true); // test Empty

  // test delete
  for (int i = 1; i <= 100; i++) {
    sk.Insert(i, i+1);
  }

  for (int i = 20; i <= 30; i++) {
    sk.Delete(i);
  }
  std::vector<int> fail;
  for (int i = 1; i <= 100; i++) {
    if (!sk.Find(i)) {
      fail.push_back(i);
    }
  }
  if (fail.size() != 11) ERROR
  for (auto && v: fail) {
    if (!(v >= 20 && v <= 30)) ERROR
  }
  sk.Clear();
  assert(ALIVE_NODE_INT == 0);
  assert(sk.Empty() == true);
  std::string res = static_cast<std::string>(success ? "TRUE" : "FALSE") + " in int test";
  LOG << res;
  return res;
}

std::string test_skiplist_slice() {
  bool success = true;
  SkipList<Slice, Slice> sk; 

  for (int i = 0; i <= 1000; i++) {
    if (!sk.Insert(i, i)) ERROR
  }

  for (int i = 0; i <= 1000; i++) {
    auto ptr = sk.Find(i);
    if (!ptr) {
      ERROR
      LOG << "cnt find\n";
    }
    else if (ptr->value_ != i) {
      LOG << "value: " << ptr->value_.ToString();
    }
  }

  sk.Clear();
  assert(ALIVE_NODE == 0); // test Clear
  assert(sk.Empty() == true); // test Empty
  
  srand(time(0));
  int rnd = rand();
  for (int i = 0; i <= 10000; i++) {
    sk.Insert(i, i + rnd);
  }

  for (int i = 0; i <= 10000; i++) {
    auto ptr = sk.Find(i);
    if (!ptr) ERROR
    else if (ptr->value_ != i + rnd) ERROR
   }
  sk.Clear();
  assert(ALIVE_NODE == 0); 
  assert(sk.Empty() == true); 
  
  // test delete
  for (int i = 1; i <= 100; i++) {
    sk.Insert(i, i+1);
  }

  for (int i = 20; i <= 30; i++) {
    sk.Delete(i);
  }
  std::vector<int> fail;
  for (int i = 1; i <= 100; i++) {
    if (!sk.Find(i)) {
      fail.push_back(i);
    }
  }
  if (fail.size() != 11) ERROR
  for (auto && v: fail) {
    if (!(v >= 20 && v <= 30)) ERROR
  }
  sk.Clear();
  assert(ALIVE_NODE == 0);
  assert(sk.Empty() == true);
  std::string res = static_cast<std::string>(success ? "TRUE" : "FALSE") + " in slice test";
  LOG << res;
  return res;
}

std::string test_slice_compress() {
  bool success = true;
  srand(time(0));

  for (int retry = 0; retry < 1000; retry++) {
    int64_t rnd_value = rand() * rand();
    std::string str = std::to_string(rnd_value);
    Slice a(rnd_value), b(str);
    Slice A = a, B = a;
    a.Compress();
    b.Compress();
    assert(a == b);
    assert(a.is_compress());
    assert(b.is_compress());
    a.UnCompress();
    b.UnCompress();
    assert(a == b);
    assert(!a.is_compress());
    assert(!b.is_compress());
    // std::cout << A.ToString() << std::endl;
    // std::cout << a.ToString() << std::endl;
    // std::cout << "size: " << A.size() << std::endl;
    // std::cout << "size: " << a.size() << std::endl;
    assert(A == a);
    assert(B == b);
    assert(A == b);
    assert(B == a);
  }
  std::string res = static_cast<std::string>(success ? "TRUE" : "FALSE") + " test_slice_compress";
  LOG << res;
  return res;
}

std::string test_log() {
  for (int i = 1; i <= 100; i++) {
    // LOG << i;
  }
  std::string res = "TRUE test_log";
  return res;
}

std::string test_db_pre() {
  bool success = true;
  auto ptr = FHdb::DataBase::single();
  //
  // test set
  //
  std::string sql = "set ";
  for (int i = 1; i <= 1000; i++) {
    sql += std::to_string(i) + " " + std::to_string(i) + " ";
  }
  ptr->ParseTheCommand(sql);
  if (ALIVE_NODE != 1000) {
    ERROR
  }
  ptr->ParseTheCommand("clear");
  if (ALIVE_NODE != 0) {
    ERROR
  }

  srand(time(0));
  std::map<Slice, Slice> mp;
  for (int i = 1; i <= 1000; i++) {
    int k = rand(), v = rand();
    if (i <= 3) {
      k = v = 1;
    }
    std::string sql = "set " + std::to_string(k) + " " + std::to_string(v);
    if (!mp.count(Slice(k))) {
      mp[Slice(k)] = Slice(v);
    }
    ptr->ParseTheCommand(sql);
  }
  if (ALIVE_NODE != mp.size()) {
    ERROR
  }
  ptr->ParseTheCommand("show");
  auto dict = ptr->dict_;

  if (dict.size() != mp.size()) {
    ERROR
  }

  for (const auto& [k, v] : dict) {
    if (mp[k] != v) {
      ERROR
    }
  }
  ptr->ParseTheCommand("clear");
  if (ALIVE_NODE != 0) {
    ERROR
  }

  std::string res = static_cast<std::string>(success ? "TRUE" : "FALSE") + " test_db_pre";
  LOG << res;
  return res;
}

std::string run_db() {
  // test command
  bool success = true;
  auto ptr = FHdb::DataBase::single();
  // ptr->close_test();
  // ptr->ParseTheCommand("  set a 1 2 3");
  // if (ptr->CommandToString() != "set a 1 2 3") ERROR
  // ptr->ParseTheCommand(" DeLet  a asdklfj asd i1   1      2 | 3");
  // if (ptr->CommandToString() != "delet a asdklfj asd i1 1 2 | 3") ERROR

  while (0) {
    printf("> ");
    std::string cmd;
    std::getline(std::cin, cmd);
    ptr->ParseTheCommand(cmd);
    printf("error: %d\n", ptr->error());
    printf("message: %s\n", ptr->message().c_str());
    if (ptr->error() == 2) {
      break;
    }
  }

  std::string res = (success ? "TRUE" : "FALSE") + static_cast<std::string>(" test_db");
  LOG << res;
  return res;
}

void TEST() {
  std::vector<std::string> test_result;
  test_result.push_back(test_slice_compress());
  test_result.push_back(test_skiplist_int());
  test_result.push_back(test_skiplist_slice());
  test_result.push_back(test_db_pre());
  test_result.push_back(run_db());
  test_result.push_back(test_log());

  for (const auto& result : test_result) {
    std::cout << result << std::endl;
    LOG << result;
  }
  return ;
}


void DB_TEST() {
  ::use_log = 0;

  srand(time(0));
  int up = 10000;
  scanf("%d", &up);
  auto ptr = FHdb::DataBase::single();
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 1; i <= up; i++) {
    ptr->ParseTheCommand("set a a");
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "skiplist_database_test_" << up << "_time_cost: ";
  printf("%d.%2ds\n",static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(end - start).count()), 
                     static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()%1000));

  ::use_log = 1;
}

}

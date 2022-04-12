#include "test.h"
#include "../log/Logging.h"
#include "../db/db.h"
#include <iostream>

namespace FHdb {

// test memory
// int cnt_delete;
// int cnt_new;

#define ERROR do{     \
  LOG << "error!";    \
  success = 0;        \
} while(0);           \

void test_skiplist_int() {
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
  LOG << (success ? "TRUE" : "FALSE") << " in int test";
}

void test_skiplist_slice() {
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
  LOG << (success ? "TRUE" : "FALSE") << " in slice test";
}

void test_slice_compress() {
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

  LOG << (success ? "TRUE" : "FALSE") << " test_slice_compress";
}

void test_log() {
  for (int i = 1; i <= 10000; i++) {
    LOG << i;
  }
}

void test_db() {
  // test command
  bool success = true;
  auto ptr = FHdb::DataBase::single();
  // ptr->ParseTheCommand("  set a 1 2 3");
  // if (ptr->CommandToString() != "set a 1 2 3") ERROR
  // ptr->ParseTheCommand(" DeLet  a asdklfj asd i1   1      2 | 3");
  // if (ptr->CommandToString() != "delet a asdklfj asd i1 1 2 | 3") ERROR

  while (true) {
    printf(">");
    std::string cmd;
    std::getline(std::cin, cmd);
    ptr->ParseTheCommand(cmd);
    printf("error: %d\n", ptr->error());
    printf("message: %s\n", ptr->message().c_str());
    if (ptr->error() == 2) {
      break;
    }
  }


  LOG << (success ? "TRUE" : "FALSE") << " test_db";
}

void TEST() {
  test_slice_compress();
  test_skiplist_int();
  test_skiplist_slice();
  // test_log();
  test_db();
}

}

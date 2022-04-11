#include "test.h"
#include "../log/Logging.h"
#include <iostream>

namespace FHdb {

// test memory
extern int cnt_delete;
extern int cnt_new;

#define ERROR do{     \
  LOG << "error!\n";  \
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
  assert(cnt_new - cnt_delete == 1); // test Clear
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
  assert(cnt_new - cnt_delete == 1); // test Clear
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
  assert(cnt_new - cnt_delete == 1);
  assert(sk.Empty() == true);
  LOG << (success ? "TRUE" : "FALSE") << " in int test\n";
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
  assert(cnt_new - cnt_delete == 1); // test Clear
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
  assert(cnt_new - cnt_delete == 1); 
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
  assert(cnt_new - cnt_delete == 1);
  assert(sk.Empty() == true);
  LOG << (success ? "TRUE" : "FALSE") << " in slice test\n";
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

  LOG << (success ? "TRUE" : "FALSE") << " test_slice_compress\n";
}

void test_log() {
  for (int i = 1; i <= 10000; i++) {
    LOG << i << "\n";
  }
}

void TEST() {
  test_slice_compress();
  test_skiplist_int();
  test_skiplist_slice();
  // test_log();
}

}

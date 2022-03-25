#include "basic/comparator.h"
#include "basic/slice.h"
#include "skiplist/skiplist.h"
#include "skiplist/node.h"

#include <iostream>

using namespace FHdb;

#define ERROR success = 0;

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
  for (int i = 0; i <= 20000; i++) {
    sk.Insert(i, i + rnd);
  }

  for (int i = 0; i <= 20000; i++) {
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
  std::cerr << (success ? "TRUE" : "FALSE") << " in int test" << std::endl;
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
      std::cerr << "cnt find" << std::endl;
    }
    else if (ptr->value_ != i) {
      std::cerr << "value: " << ptr->value_.ToString();
    }
  }

  sk.Clear();
  assert(cnt_new - cnt_delete == 1); // test Clear
  assert(sk.Empty() == true); // test Empty
  
  srand(time(0));
  int rnd = rand();
  for (int i = 0; i <= 20000; i++) {
    sk.Insert(i, i + rnd);
  }

  for (int i = 0; i <= 20000; i++) {
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
  std::cerr << (success ? "TRUE" : "FALSE") << " in slice test" << std::endl;
}

void TEST() {
  test_skiplist_int();
  test_skiplist_slice();
}

int main() {
  TEST();
}

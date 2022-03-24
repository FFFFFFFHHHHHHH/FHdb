#include <iostream>

#include "basic/comparator.h"
#include "basic/slice.h"
#include "skiplist/skiplist.h"
#include "skiplist/node.h"

using namespace FHdb;

bool test() {
#define ERROR success = 0;
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
  std::cerr << "test ok";
  return success;
}

int main() {
  std::cerr << "test sucess " << test();
}

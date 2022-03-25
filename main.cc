#include "basic/comparator.h"
#include "basic/slice.h"
#include "skiplist/skiplist.h"
#include "skiplist/node.h"

#include <iostream>

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

  sk.Clear();
  assert(cnt_new - cnt_delete == 1); // test Clear
  assert(sk.Empty() == true); // test Empty
  
  srand(time(0));
  int rnd = rand();
  for (int i = 0; i <= 100000; i++) {
    sk.Insert(i, i + rnd);
  }

  for (int i = 0; i <= 100000; i++) {
    auto ptr = sk.Find(i);
    if (!ptr) ERROR
    else if (ptr->value_ != i + rnd) ERROR
  }

  sk.Clear();
  printf("cnt_new:%d cnt_delete:%d\n", cnt_new, cnt_delete);
  assert(cnt_new - cnt_delete == 1); // test Clear
  assert(sk.Empty() == true); // test Empty

  return success;
}

int main() {
  std::cerr << " test sucess :" << (test() ? "true" : "false")  << std::endl;
}

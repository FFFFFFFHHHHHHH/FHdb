#pragma once
#include "../basic/comparator.h"
#include "../basic/slice.h"
#include "../skiplist/skiplist.h"
#include "../skiplist/node.h"

namespace FHdb { 

template <typename K = Slice, typename V = Slice>
size_t AliveNode() {
  return Node<K, V>::cnt_new - Node<K, V>::cnt_delete - 1;
}

#define ALIVE_NODE AliveNode<Slice, Slice>()

#define ALIVE_NODE_INT AliveNode<int, int>()

#define TEST_ON

void test_skiplist_int();

void test_skiplist_slice();

void test_slice_compress();

void TEST();

}

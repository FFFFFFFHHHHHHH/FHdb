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

//#define CHECK_ON

std::string test_skiplist_int();

std::string test_skiplist_slice();

std::string test_slice_compress();

std::string test_db_pre();

std::string test_log();

void test_db();

void TEST();

}

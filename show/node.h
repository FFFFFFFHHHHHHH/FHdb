#pragma once
#include <vector>
#include <iostream>
#include <memory>

#include "../basic/slice.h"
#include "../basic/comparator.h"

namespace FHdb {

// int cnt_delete;
// int cnt_new;

// test memory
template <typename K, typename V>
class Node {
public:
  Node() = delete;
  Node(const Node&) = delete;
  Node& operator = (const Node&) = delete;
  Node(const K& key, const V& value, const size_t& level);
  K get_key() const;
  V get_value() const;

  K key_;
  V value_;
  size_t level_;
  std::vector<std::shared_ptr<Node<K, V>>> forward_;
};

template <typename K, typename V>
int Node<K, V>::cnt_delete = 0;
template <typename K, typename V>
int Node<K, V>::cnt_new = 0;


}

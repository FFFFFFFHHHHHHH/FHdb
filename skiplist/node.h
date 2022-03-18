#pragma once
#include "../basic/slice.h"
#include "../basic/comparator.h"

namespace FHdb {

template <typename K, typename V>
struct Node {
  Node() = delete;

  Node(const K& key, const V& value) :
    key_(key), value_(value) {}
  
  K get_key() const {
    return key_;
  }

  V get_value() const {
    return value_;
  }

  K key_;
  V value_;
  size_t level_;
  std::vector<std::shared_ptr<Node>> forward_;
};

}

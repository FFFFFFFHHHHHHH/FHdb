#pragma once
#include <vector>
#include "../basic/slice.h"
#include "../basic/comparator.h"

namespace FHdb {

template <typename K, typename V>
class Node {
public:

  Node() = delete;

  Node(const K& key, const V& value, const size_t& level) :
    key_(key), value_(value), level_(level) {
      forward_.resize(level_, nullptr);
    }
  
  K get_key() const {
    return key_;
  }

  V get_value() const {
    return value_;
  }

  K key_;
  V value_;
  size_t level_;
  std::vector<std::shared_ptr<Node<K, V>>> forward_;

};


}

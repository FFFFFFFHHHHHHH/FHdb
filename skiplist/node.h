#pragma once
#include <vector>
#include <iostream>
#include <memory>

#include "../basic/slice.h"
#include "../basic/comparator.h"

namespace FHdb {

// test memory
int cnt_delete = 0;
int cnt_new = 0;

template <typename K, typename V>
class Node {
public:

  Node() = delete;

  ~Node() {
    cnt_delete++;
  }

  Node(const K& key, const V& value, const size_t& level) :
    key_(key), value_(value), level_(level) {
      forward_.resize(level_, nullptr);
      cnt_new++;
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

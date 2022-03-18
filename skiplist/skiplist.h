#pragma once
#include "../basic/slice.h"
#include "../basic/comparator.h"
#include "node.h"
#include "random.h"

namespace FHdb {

template <typename K, typename V>
class SkipList {

public:

  size_t GetRandom();

private:
  std::shared_ptr<Node<K,V>> head_;
  std::shared_ptr<Node<K,V>> tail_;
  size_t level_;
  size_t node_cnt_;
  static const size_t MAX_LEVEL = 20;
  Random rnd_;
};

template <typename K, typename V>
size_t SkipList<K, V>::GetRandom() {
  size_t level = static_cast<size_t>(rnd_.Uniform(MAX_LEVEL));
  if (level == 0) {
    level++;
  }
  return level;
}

}

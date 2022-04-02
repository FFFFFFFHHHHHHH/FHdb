#pragma once
#include "../basic/slice.h"
#include "../basic/comparator.h"
#include "node.h"
#include "random.h"
#include <iostream>

namespace FHdb {

template <typename K, typename V>
class SkipList {

public:

  SkipList();

  std::shared_ptr<Node<K, V>> Find(const K& key);
  
  bool Insert(const K& key, const V& value);

  bool Delete(const K& key);

  bool Clear();

  bool Empty();

private:
  std::shared_ptr<Node<K, V>> CreateNode(const K& key, const V& value, const size_t& level);

  size_t GetRandomLevel();

private:
  std::shared_ptr<Node<K,V>> head_;
  size_t level_;
  size_t node_cnt_;
  constexpr static size_t MAX_LEVEL = 20;
  Random rnd_;
  Comparator<K> cmp_;
};

template <typename K, typename V>
std::shared_ptr<Node<K, V>> SkipList<K, V>::CreateNode(
                            const K& key, const V& value, const size_t& level) {
  std::shared_ptr<Node<K, V>> ptr = std::make_shared<Node<K, V>>(key, value, level);
  return ptr;
}

template <typename K, typename V>
SkipList<K, V>::SkipList() : rnd_(123456789) {
  head_ = CreateNode(K(), V(), MAX_LEVEL); // ???
  level_ = 0;
}

template <typename K, typename V>
std::shared_ptr<Node<K, V>> SkipList<K, V>::Find(const K& key) {
  std::shared_ptr<Node<K, V>> node = head_;
  assert(node != nullptr);
  assert(level_ >= 0 && level_ <= MAX_LEVEL);
  // std::cerr << "start find\n";
  for (int i = level_ - 1; i >= 0; i--) {
    while (node->forward_[i] && cmp_.Less(node->forward_[i]->key_, key)) {
      node = node->forward_[i];
    }
  }
  // std::cerr << "node.val" << node->value_ << "\n";
  assert(node != nullptr);
  if (node->forward_[0] && cmp_.Equal(node->forward_[0]->key_, key)) {
    return node->forward_[0];
  } else {
    return nullptr;
  }
}

template <typename K, typename V>
bool SkipList<K, V>::Insert(const K& key, const V& value) {
  // std::cerr << "start find" << std::endl;
  if (Find(key)) {
    return false; // have is key
  }
  // std::cerr << "find over \n";
  std::shared_ptr<Node<K, V>> node = head_;
  assert(node != nullptr);
  assert(level_ >= 0 && level_ <= MAX_LEVEL);
  std::vector<std::shared_ptr<Node<K, V>>> update(MAX_LEVEL, head_);

  for (int i = static_cast<int>(level_ - 1); i >= 0; --i) {
    while (node->forward_[i] && cmp_.Less(node->forward_[i]->key_, key)) {
      node = node->forward_[i];
    }
    assert(i < static_cast<int>(update.size()));
    update[i] = node;
  }

  size_t new_level = GetRandomLevel();
  auto new_node = CreateNode(key, value, new_level);
  assert(new_node != nullptr);
  if (!new_node) {
    return false;
  }
  if (new_level > level_) {
    new_level = ++level_;
  }
  // std::cerr << "level: " << new_level << std::endl;
  for (size_t i = 0; i < new_level; i++) {
    new_node->forward_[i] = update[i]->forward_[i];
    update[i]->forward_[i] = new_node;
  }
  
  return true;
}

template <typename K, typename V>
bool SkipList<K, V>::Delete(const K& key) {
  auto delete_node = Find(key);
  if (!delete_node) {
    return false;
  }

  std::shared_ptr<Node<K, V>> node = head_;
  assert(node != nullptr);
  assert(level_ >= 0 && level_ <= MAX_LEVEL);
  std::vector<std::shared_ptr<Node<K, V>>> update(MAX_LEVEL, head_);

  for (int32_t i = static_cast<int32_t>(level_ - 1); i >= 0; --i) {
    while (node->forward_[i] && cmp_.Less(node->forward_[i]->key_, key)) {
      node = node->forward_[i];
    }
    assert(i < static_cast<int32_t>(update.size()));
    update[i] = node;
  }

  size_t delete_level = delete_node->level_;
  for (size_t i = 0; i < delete_level; ++i) {
    update[i]->forward_[i] = delete_node->forward_[i];
  }
  
  return true;
}

template <typename K, typename V>
size_t SkipList<K, V>::GetRandomLevel() {
  size_t level = static_cast<size_t>(rnd_.Uniform(MAX_LEVEL));
  return level + 1;
}

template <typename K, typename V>
bool SkipList<K, V>::Empty() {
  bool empty = true;
  for (int i = level_ - 1; i >= 0; i--) {
    if (head_->forward_[i]) {
      empty = false;
      break;
    }
  }
  assert(empty == (level_ == 0));
  return empty;
}

template <typename K, typename V>
bool SkipList<K, V>::Clear() {
  // reset head node 
  head_ = std::make_shared<Node<K, V>>(K(), V(), MAX_LEVEL);
  level_ = 0;
  return true;
}

}



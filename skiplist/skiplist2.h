#include <vector>
#include <memory>
#include <iostream>
#include <cstring>

template <typename K, typename V>
class Node {
public:

  Node() = delete;
  Node(const Node&) = delete;
  Node& operator = (const Node&) = delete;
  ~Node() {}

  Node(const K& key, const V& value, const size_t& level) :
    key_(key), value_(value), level_(level) {
      // forward_.resize(level_, nullptr);
      forward_ = new Node<K, V>*[level_];
      memset(forward_, 0, sizeof(Node<K, V>*) * (level_));
    }
  K key_;
  V value_;
  size_t level_;
  Node<K, V> ** forward_;
  //std::vector<std::shared_ptr<Node<K, V>>> forward_;
};


template <typename K, typename V>
class SkipList {
public:
  SkipList();
  bool Insert(const K& key, const V& value);
private:
  std::shared_ptr<Node<K, V>> CreateNode(const K& key, const V& value, const size_t& level);
  Node<K, V>* CreateNode1(const K& key, const V& value, const size_t& level);
  size_t GetRandomLevel();
private:
  // std::shared_ptr<Node<K, V>> head_;
  Node<K, V>* head_;
  size_t level_;
  size_t MAX_LEVEL = 21;
};

template <typename K, typename V>
std::shared_ptr<Node<K, V>> SkipList<K, V>::CreateNode(
                            const K& key, const V& value, const size_t& level) {
  std::shared_ptr<Node<K, V>> ptr = std::make_shared<Node<K, V>>(key, value, level);
  return ptr;
}

template <typename K, typename V>
Node<K, V>* SkipList<K, V>::CreateNode1(
                            const K& key, const V& value, const size_t& level) {
  return new Node<K, V>(key, value, level);
}

template <typename K, typename V>
SkipList<K, V>::SkipList() {
  head_ = CreateNode1(K(), V(), MAX_LEVEL); 
  level_ = 0;
  MAX_LEVEL = 21;
}
template <typename K, typename V>
bool SkipList<K, V>::Insert(const K& key, const V& value) {
  auto node = head_;
  //std::vector<std::shared_ptr<Node<K, V>>> update(MAX_LEVEL, head_);
  Node<K, V>** update = new Node<K, V>*[MAX_LEVEL];
  for (int i = 0; i < MAX_LEVEL; i++) update[i] = head_;
  for (int i = static_cast<int>(level_ - 1); i >= 0; --i) {
    while (node->forward_[i] && node->forward_[i]->key_ < key/*cmp_.Less(node->forward_[i]->key_, key)*/) {
      node = node->forward_[i];
    }
    update[i] = node;
  }
  node = node->forward_[0];
  if (node && key == node->key_) {
    return 0;
  }

  size_t new_level = GetRandomLevel();
  auto new_node = CreateNode1(key, value, new_level);
  // assert(new_node != nullptr);
  if (!new_node) {
    return false;
  }
  if (new_level > level_) {
    new_level = ++level_;
  }
  for (size_t i = 0; i < new_level; i++) {
    new_node->forward_[i] = update[i]->forward_[i];
    update[i]->forward_[i] = new_node;
  }
  
  return true;
}

template <typename K, typename V>
size_t SkipList<K, V>::GetRandomLevel() {
  size_t level = 1;
  while (rand() % 2) {
    level++;
  }
  level = std::min(level, MAX_LEVEL);
  return level;
}

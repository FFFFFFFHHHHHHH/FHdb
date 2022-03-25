#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <memory>
#include <assert.h>

namespace FHdb {

class Slice {

public:
  Slice() : data_(""), size_(0) {}

  Slice(const char* data, size_t size) : data_(std::string(data, size)), size_(size) {}

  Slice(const char* data) : data_(std::string(data, strlen(data))), size_(strlen(data)) {}

  Slice(const std::string& str) : data_(str), size_(str.size()) {}

  Slice(int rhs) {
    data_ = std::to_string(rhs);
    size_ = data_.size();
  }

  Slice(const Slice& rhs) : data_(rhs.data_), size_(rhs.size_) {}
  
  Slice& operator = (const Slice& rhs) = delete;

  size_t size() {
    return size_;
  }

  bool empty() { 
    return size_ == 0;
  }

  void clear() {
    data_ = "";
    size_ = 0;
  }

  char operator [](size_t idx) const {
    assert(idx < size_);
    return data_[idx];
  }

  std::string ToString() const {
    return std::string(data_, size_);
  }

  void remove_prefix(size_t n) {
    assert(n <= size_);
    size_ -= n;
    data_ += n;
  }

  bool start_with(const Slice& x) {
    return (x.size_ <= size_) && (memcmp(data_.data(), x.data_.data(), x.size_));
  }

  int compare(const Slice& x) const {
    size_t min_len = std::min(size_, x.size_);
    for (int i = 0; i < min_len; i++) {
      if (data_[i] != x.data_[i]) {
        return data_[i] < x.data_[i] ? -1 : 1;
      }
    }
    return size_ == x.size_ ? 0 :
            size_ < x.size_ ? -1 : 1;
  }


  bool operator == (const Slice& rhs) {
    return (size_ == rhs.size_)
                  && (memcmp(data_.data(), rhs.data_.data(), size_) == 0);
  }

  bool operator != (const Slice& rhs) {
    return !(*this == rhs);
  }

private:
  std::string data_;
  size_t size_;
};

}

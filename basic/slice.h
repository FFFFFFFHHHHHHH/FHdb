#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <memory>
#include <assert.h>

namespace FHdb {

class Slice {

public:
  Slice() : data_(""), size_(0), is_compress_(0) {}

  Slice(const char* data, size_t size) : 
    data_(std::string(data, size)), size_(size), is_compress_(0) {}

  Slice(const char* data) : 
    data_(std::string(data, strlen(data))), size_(strlen(data)), is_compress_(0) {}

  Slice(const std::string& str) : 
    data_(str), size_(str.size()), is_compress_(0) {}

  Slice(int64_t rhs) {
    data_ = std::to_string(rhs);
    size_ = data_.size();
    is_compress_ = 0;
  }

  Slice(const Slice& rhs) : data_(rhs.data_), size_(rhs.size_), is_compress_(rhs.is_compress_) {}
  
  Slice& operator = (const Slice& rhs) {
    if (this != &rhs) {
      data_ = rhs.data_;
      size_ = rhs.size_;
      is_compress_ = rhs.is_compress_;
    }
    return *this;
  }

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
    return data_;
  }

  void remove_prefix(size_t n) {
    assert(n <= size_);
    size_ -= n;
    data_ += n;
  }

  bool start_with(const Slice& x) {
    return (x.size_ <= size_) && (memcmp(data_.data(), x.data_.data(), x.size_));
  }

  bool is_compress() {
    return is_compress_;
  }

  int compare(const Slice& x) const {
    size_t min_len = std::min(size_, x.size_);
    for (size_t i = 0; i < min_len; i++) {
      if (data_[i] != x.data_[i]) {
        return data_[i] < x.data_[i] ? -1 : 1;
      }
    }
    return size_ == x.size_ ? 0 :
            size_ < x.size_ ? -1 : 1;
  }


  bool operator == (const Slice& rhs) {
    return (is_compress_ == rhs.is_compress_) && (size_ == rhs.size_)
                  && (memcmp(data_.data(), rhs.data_.data(), size_) == 0);
  }

  bool operator != (const Slice& rhs) {
    return !(*this == rhs);
  }

  void Compress();

  void UnCompress();

private:

  std::string data_;
  size_t size_;
  bool is_compress_ = false;
};

}

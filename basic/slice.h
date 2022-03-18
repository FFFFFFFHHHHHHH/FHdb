#pragma once
#include <string>
#include <cstring>

namespace FHdb {

class Slice {

public:
  Slice() : data_(""), size_() {}

  Slice(const char* data, size_t size) : data_(data), size_(size) {}

  Slice(const char* data) : data_(data), size_(strlen(data)) {}

  Slice(const std::string& str) : data_(str.data()), size_(str.size()) {}

  Slice(const Slice&) = default;
  
  Slice& operator = (const Slice&) = default;

  const char* data() {
    return data_;
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
    return std::string(data_, size_);
  }

  void remove_prefix(size_t n) {
    assert(n <= size_);
    size_ -= n;
    data_ += n;
  }

  bool start_with(const Slice& x) {
    return (x.size_ <= size_) && (memcmp(data_, x.data_, x.size_));
  }

  int compare(const Slice& x) {
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
                  && (memcmp(data_, rhs.data_, size_) == 0);
  }

  bool operator != (const Slice& rhs) {
    return !(*this == rhs);
  }

private:
  const char* data_;
  size_t size_;
};

}

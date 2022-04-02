#include "slice.h"

namespace FHdb {

void Slice::Compress() {
  if (is_compress_) {
    return ;
  }
  if (data_.size() > 18) {
    return ;
  }
  int64_t num_val = 0;
  int64_t flag = 1;
  if (data_[0] == '-') {
    flag = -1; 
  }
  for (size_t i = (flag == -1); i < data_.size(); ++i) {
    if (!std::isdigit(data_[i])) {
      return ;
    }
    num_val = num_val * 10 + (data_[i] - '0');
  }
  num_val *= flag;
  int8_t *num_ptr = reinterpret_cast<int8_t*>(&num_val);
  data_.clear();
  for (int i = 7; i >= 0; --i) {
    if ( *(num_ptr + i) ==  0 && data_.size() == 0) {
      continue ;
    }
    data_.push_back(*(num_ptr + i));
  }
  if (!data_.size()) {
    data_.push_back(0);
  }
  size_ = data_.size();
  is_compress_ = true;
  return ;
} 

void Slice::UnCompress() {
  if (is_compress_ == false) {
    return ;
  }
  assert(data_.size() <= 18);
  int64_t num_val = 0;
  assert(data_.size() <= 8);
  int8_t* num_ptr = reinterpret_cast<int8_t*>(&num_val);
  if (data_.size() < 8) {
    data_ = std::string(8 - data_.size(), 0) + data_;
  }
  assert(data_.size() == 8);
  for (int i = 7; i >= 0; --i) {
    *(num_ptr + i) = data_[7 - i];
  }
  data_.clear();
  data_ = std::to_string(num_val);
  size_ = data_.size();
  is_compress_ = false;
  return ;
}

}

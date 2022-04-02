#pragma once
#include "slice.h"

namespace FHdb {

template <typename T>
class Comparator {

public:
  int Compare(const T& lhs, const T& rhs) {
    return lhs.compare(rhs);
  }
  
  bool Greater(const T& lhs, const T& rhs) {
    return lhs.compare(rhs) > 0;
  }

  bool Less(const T& lhs, const T& rhs) {
    return lhs.compare(rhs) < 0;
  }

  bool Equal(const T& lhs, const T& rhs) { 
    return lhs.compare(rhs) == 0;
  }

  bool EqualOrGreater(const T& lhs, const T& rhs) {
    return lhs.compare(rhs) >= 0;
  }

  bool EqualOrLess(const T& lhs, const T& rhs) { 
    return lhs.compare(rhs) <= 0;
  }    
};


template <>
class Comparator<int> {

public:
  int Compare(const int& lhs, const int& rhs) {
    return lhs == rhs ? 0 :
              lhs > rhs ? 1 : -1;
  }
  
  bool Greater(const int& lhs, const int& rhs) {
    return lhs > rhs;
  }

  bool Less(const int& lhs, const int& rhs) {
    return lhs < rhs;
  }

  bool Equal(const int& lhs, const int& rhs) { 
    return lhs == rhs;
  }

  bool EqualOrGreater(const int& lhs, const int& rhs) {
    return lhs >= rhs;
  }

  bool EqualOrLess(const int& lhs, const int& rhs) { 
    return lhs <= rhs;
  }    
};

template <>
class Comparator<std::string> {

public:
  
  bool Less(const std::string& lhs, const std::string& rhs) {
    for (size_t i = 0; i < std::min(lhs.size(), rhs.size()); i++) {
      if (lhs[i] != rhs[i]) {
        if (lhs[i] < rhs[i]) return true;
        else return false;
      }
    }
    return rhs.size() > lhs.size();
  }

  bool Equal(const std::string& lhs, const std::string& rhs) { 
    return lhs == rhs;
  }
};


}

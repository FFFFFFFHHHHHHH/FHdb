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

  bool EqualAndGreater(const T& lhs, const T& rhs) {
    return lhs.compare(rhs) >= 0;
  }

  bool greater(const T& lhs, const T& rhs) { 
    return lhs.compare(rhs) <= 0;
  }    
};

}

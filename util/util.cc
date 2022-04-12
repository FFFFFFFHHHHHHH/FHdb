#include "util.h"


namespace util {


uint64_t Hash(const char *str) {
  uint64_t h = 0, g = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    h = (h << 4) + *(str + i);
    if ((g = (h & 0xF0000000))) {
      h = h ^ (g >> 24);
      h = h ^ g;
    }
  }
  return h;
}


}

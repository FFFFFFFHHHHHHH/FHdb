#include "FileUtil.h"


AppendFile::AppendFile(std::string file_name) {
  fp_ = fopen(file_name.c_str(), "ae");
  setbuffer(fp_, buffer_, sizeof buffer_);
}


void AppendFile::append(const char* str, const size_t len) {
  // printf("%s", str);
  size_t n = write(str, len);
  size_t rest = len - n;
  while (rest > 0) {
    size_t nn = write(str + n, rest);
    if (!nn) {
      int err = ferror(fp_);
      if (err) {
        fprintf(stderr, "file error!\n");
        break;
      }
      n += nn;
      rest -= nn;
    }
  }
  // flush();
}


void AppendFile::flush() {
  fflush(fp_);
}


size_t AppendFile::write(const char* str, const size_t len) {
  return fwrite_unlocked(str, 1, len, fp_);
}

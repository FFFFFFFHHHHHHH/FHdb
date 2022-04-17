#pragma once
#include "noncopyable.h"
#include <string>
#include <fcntl.h> 

class AppendFile : noncopyable{

public:
  explicit AppendFile(std::string file_name = "log");

  ~AppendFile() {}

  void append(const char* str, const size_t len);

  void flush();

private:
  size_t write(const char* str, const size_t len);

  char buffer_[1024 * 64];
  FILE *fp_;
};

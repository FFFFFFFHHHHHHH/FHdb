#pragma once
#include "AsyncLogging.h"

#include <time.h>
#include <sys/time.h>

#define LOG Logging(__FILE__, __LINE__).Stream()

class Logging {

public:
  Logging(const char* file_name, int line);

  ~Logging();

  LogStream& Stream() {
    return stream_;
  }

private:

  const char* file_name_;

  int line_;

  void AddTime();

  LogStream stream_;

};

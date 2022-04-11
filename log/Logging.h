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

  void AddTime();

  LogStream stream_;

  std::string LogFilePath_;

};
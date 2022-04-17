#pragma once
#include "AsyncLogging.h"

#include <time.h>
#include <sys/time.h>

#define LOG Logging(__FILE__, __LINE__).Stream()

#define AOF Logging("aof_log").Stream()

class Logging {

public:
  Logging() = delete;

  Logging(const Logging&) = delete;

  Logging& operator = (const Logging&) = delete;
  
  Logging(const char* file_name, int line, const char* path = "db_log");

  Logging(const char* path = "aof_log");

  ~Logging();

  LogStream& Stream() {
    return stream_;
  }

private:

  const char* file_name_;

  int line_;

  void AddTime();

  LogStream stream_;

  std::shared_ptr<AsyncLogging> async_log_ptr;

};

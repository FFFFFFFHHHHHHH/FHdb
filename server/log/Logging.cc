#include "Logging.h"

Logging::Logging(const char* file_name, int line, const char* path) : 
  file_name_(file_name),
  line_(line) {
  AddTime();
  async_log_ptr = AsyncLogging::db_log_single(path);
}

Logging::Logging(const char* path) {
  async_log_ptr = AsyncLogging::aof_log_single(path);
}

void Logging::AddTime() {
  char str_t[26] = {0};
  struct timeval tv;
  time_t time;
  gettimeofday(&tv, NULL);
  time = tv.tv_sec;
  struct tm* p_time = localtime(&time);
  strftime(str_t, 26, "%Y-%m-%d %H:%M:%S|  ", p_time);
  stream_ << str_t;
}

Logging::~Logging() {
  stream_ << "\n";
  async_log_ptr->Append(stream_.buffer().data(), stream_.buffer().length());
}

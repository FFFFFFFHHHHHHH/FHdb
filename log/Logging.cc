#include "Logging.h"

Logging::Logging(const char* file_name, int line) : 
  LogFilePath_("log"){
  AddTime();
  stream_ << "(" << file_name << ":" << line << ")\n";
}

void Logging::AddTime() {
  char str_t[26] = {0};
  struct timeval tv;
  time_t time;
  gettimeofday(&tv, NULL);
  time = tv.tv_sec;
  struct tm* p_time = localtime(&time);
  strftime(str_t, 26, "%Y-%m-%d %H:%M:%S\n", p_time);
  stream_ << str_t;
}

Logging::~Logging() {
  AsyncLogging::single()->Append(stream_.buffer().data(), stream_.buffer().length());
}

#pragma once
#include "FileUtil.h"
#include <mutex>
#include <memory>

// 保证 线程安全 和 定期刷新

class LogFile : noncopyable {

public:
  /*explicit*/ LogFile(const std::string& file_name = "log", size_t flush_every_n = 1024);

  void Append(const char* logline, const size_t len);

  void flush();

private:

  size_t cnt_;
  const size_t flush_every_n_;

  std::string file_name_;

  std::mutex mu_;
  std::unique_ptr<AppendFile> file_;
};

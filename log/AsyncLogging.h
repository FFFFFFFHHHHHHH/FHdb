#pragma once
#include "LogStream.h"
#include "LogFile.h"

#include <mutex>
#include <thread>
#include <condition_variable>
#include <memory>
#include <vector>
#include <atomic>
#include <unistd.h>

class AsyncLogging : noncopyable{

public:
  void Append(const char* buf, size_t len);

  ~AsyncLogging();

  static std::shared_ptr<AsyncLogging> db_log_single(const std::string& path = "db_log") {
    static std::shared_ptr<AsyncLogging> single_ptr = std::make_shared<AsyncLogging>(path);
    return single_ptr;
  }

  // static AsyncLogging* db_log_single(const std::string& path = "db_log") {
  //   static AsyncLogging* ptr = new AsyncLogging(path);
  //   return ptr;
  // }

  static std::shared_ptr<AsyncLogging> aof_log_single(const std::string& path = "aof_log") {
    static std::shared_ptr<AsyncLogging> single_ptr = std::make_shared<AsyncLogging>(path);
    return single_ptr;
  }

  AsyncLogging(const std::string path);

  void stop();

private:

  void thread_func();

  typedef FixedBuffer<kSmallBuffer> Buffer;
  typedef std::shared_ptr<Buffer> BufferPtr;
  typedef std::vector<BufferPtr> Buffers;

  BufferPtr current_;
  Buffers buffers_;
  Buffers buffers_to_write_;

  std::string path_;

  std::mutex mutex_;
  std::condition_variable cv_;
  std::unique_ptr<std::thread> thread_;

  std::atomic<bool> running_;

};

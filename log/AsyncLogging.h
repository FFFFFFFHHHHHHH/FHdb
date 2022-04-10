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

  static AsyncLogging* single() {
    static AsyncLogging* single_ptr = new AsyncLogging();
    return single_ptr;
  }

  AsyncLogging(const std::string file_name = "log");

  void stop();

private:

  void thread_func();

  typedef FixedBuffer<kSmallBuffer> Buffer;
  typedef std::shared_ptr<Buffer> BufferPtr;
  typedef std::vector<BufferPtr> Buffers;

  BufferPtr current_;
  Buffers buffers_;
  Buffers buffers_to_write_;

  std::string file_name_;

  std::mutex mutex_;
  std::condition_variable cv_;
  std::unique_ptr<std::thread> thread_;

  std::atomic<bool> running_;

};

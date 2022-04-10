#include "AsyncLogging.h"


AsyncLogging::AsyncLogging(const std::string file_name) : 
  current_(std::make_shared<Buffer>()), 
  file_name_(file_name), 
  mutex_(), 
  cv_(),
  running_(false) {
  thread_ = std::make_unique<std::thread>(&AsyncLogging::thread_func, this);
  running_.store(true);
}

AsyncLogging::~AsyncLogging() {
  if (running_) {
    stop();
  }
}

void AsyncLogging::stop() {
  running_.store(false);
  cv_.notify_all();
  thread_->join();
}

void AsyncLogging::Append(const char* buf, size_t len) {
  std::unique_lock<std::mutex> lo(mutex_);
  if (current_->avail() > static_cast<int>(len)) {
    current_->append(buf, len);
  } else {
    buffers_.push_back(current_);
    current_.reset(new Buffer);
    current_->append(buf, len);
  }
  cv_.notify_all();
}

void AsyncLogging::thread_func() {
  LogFile logfile(file_name_);
  buffers_.clear();
  buffers_to_write_.clear();
  while (running_ == true) {
    {
      std::unique_lock<std::mutex> lo(mutex_);
      while (running_ && current_->length() == 0 && buffers_.size() == 0) {
        cv_.wait(lo);
      }
      buffers_.push_back(current_);
      current_.reset(new Buffer);
      std::swap(buffers_, buffers_to_write_);
      assert(buffers_.size() == 0);
    }
    for (const auto & buffer : buffers_to_write_) {
      logfile.Append(buffer->data(), buffer->length());
    }
    buffers_to_write_.clear();
    logfile.flush();
  }
}

#include "LogFile.h"

LogFile::LogFile(const std::string& file_name, size_t flush_every_n) : 
   cnt_(0), flush_every_n_(flush_every_n), file_name_(file_name) {
  file_ = std::make_unique<AppendFile>(file_name_);
}

void LogFile::Append(const char* logline, const size_t len) {
  std::unique_lock<std::mutex> lock(mu_);
  file_->append(logline, len);
  if (++cnt_ > flush_every_n_) {
    file_-> flush();
  }
}
  
void LogFile::flush() {
  std::unique_lock<std::mutex> lock(mu_);
  file_->flush();
  cnt_ = 0;
}


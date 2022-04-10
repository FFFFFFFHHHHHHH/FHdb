#include "iostream"
#include "string.h"
#include "AsyncLogging.h"
#include "Logging.h"

#include <iostream>

int main() {
  // auto ptr = AsyncLogging::single();
  // const char* str1 = "123456\n";
  // const char* str2 = "hello\n";
  // ptr->Append(str1, strlen(str1));
  // ptr->Append(str2, strlen(str2));
  LOG << "only test\n";
  sleep(1);
  // ptr->stop();
  return 0;
}




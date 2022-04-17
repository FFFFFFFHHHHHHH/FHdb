#include <unistd.h>
#include "webserver.h"

int main() {
  WebServer server(
      1234, 3, 60000, false,
      3306, "root", "root","webserver", 
      12, 1, true, 1, 1024
      );
  server.Start();
  return 0;
}

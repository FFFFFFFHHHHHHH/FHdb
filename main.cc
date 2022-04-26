#include "skiplist/skiplist.h"
#include "test/test.h"
#include "log/Logging.h"
#include  "db/db.h"
#include "server/webserver.h"

#include <iostream>

int main() {

#ifdef TEST_ON
  FHdb::TEST();
#endif

  FHdb::DataBase::single()->close_test();
  WebServer server(
      3389, 3, 60000, false,
      3306, "root", "root","webserver", 
      12, 1, true, 1, 1024
      );

  server.Start();

  return 0;
}


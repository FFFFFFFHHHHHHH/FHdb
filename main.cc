#include "skiplist/skiplist.h"
#include "test/test.h"
#include "log/Logging.h"
#include  "db/db.h"

#include <iostream>

int main() {

  AOF << "just test";

#ifdef TEST_ON
  FHdb::TEST();
#endif

  AOF << "just test";

  return 0;
}


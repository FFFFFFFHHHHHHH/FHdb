#include "skiplist.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <pthread.h>
#include <time.h>

int main() {
  srand(time(0));
  int up = 10000;
  scanf("%d", &up);
  FHdb::SkipList<int, std::string> skipList_db;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 1; i <= up; i++) {
		skipList_db.Insert(rand(), std::to_string(rand())); 
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "skipList_test_" << up << "_time_cost: ";
  printf("%d.%2ds\n",static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(end - start).count()), 
                     static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()%1000));
}

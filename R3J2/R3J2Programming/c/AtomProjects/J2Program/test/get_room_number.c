#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRoomId(int floors, int rooms);

int main () {

  srand((unsigned) time (NULL));

  printf("%d\n", getRoomId(5, 5));

  return 0;

}

int getRoomId(int floors, int rooms) {

  int f = rand() % floors + 1;
  int r = rand() % rooms + 1;

  return f * 100 + r;

}

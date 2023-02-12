#include <stdlib.h>
#include <time.h>

int Random(int integer) {
  return rand() % integer;
}

int dice() {
  return rand() % 6 + 1;
}

int randomMinToMax(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

void initSeed() {
  srand((unsigned) time (NULL));
}

#include <stdlib.h>
#include <time.h>

int dice() {

  return rand() % 6 + 1;

}

int Random(int x) {

  return rand() % (x + 1);

}

int random_plus(int x) {

  return rand() % x + 1;

}

int random_min_to_max(int min, int max) {

  return rand() % (max - min) + min + 1;

}

void init_seed() {
  srand((unsigned) time (NULL));
}

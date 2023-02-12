#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stats[4] = {0, 0, 0, 0};
const char label[4][4] = {"HP", "ATK", "DEF", "AGI"};

int Random(int n) {

    return rand() % n;

}

int main () {

  srand((unsigned)time(NULL));

  for (int i = 0; i < 100; i++) {
    stats[Random(4)]++;
  }

  for (int i = 0; i < 4; i++) {
    printf("%s: %d\n", label[i], stats[i]);
  }

  return 0;

}

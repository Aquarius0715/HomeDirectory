#include "io.h"
#include <stdlib.h>
#include <time.h>

int main () {

  srand((unsigned) time (NULL));

  int all = 0;
  double avg = 0;
  int max = 0;

  for (int i = 0; i < 617; i++) {

    int rnd = rand() % (32767 + 1);

    all += rnd;
    if (rnd > max) {
        max = rnd;
    }
  }

  avg = all / 617;

  printf("(1) sum = %d\n", all);
  printf("(2) avg = %f\n", avg);
  printf("(3) max = %d\n", max);

  return 0;

}

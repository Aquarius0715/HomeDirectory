#include "io.h"

int calc_sum();

int main () {

  printf("1976 kara 2021 no wa ha %d desu\n", calc_sum());

  return 0;

}

int calc_sum() {

  int sum = 0;

  for (int i = 1976; i <= 2021; i++) {
    sum += i;
  }

  return sum;

}

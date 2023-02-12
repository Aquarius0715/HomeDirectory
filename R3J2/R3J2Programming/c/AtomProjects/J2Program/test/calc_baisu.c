#include <stdio.h>

int calc_baisu();

int main () {

  printf("1 ~ 1000 no 4 no baisuu ha %d desu\n", calc_baisu());

  return 0;

}

int calc_baisu() {

  int sum = 0;

  for (int i = 1; i <= 1000; i++) {
    //printf("%d\n", i);
    if (i % 4 == 0 && i != 0) {
      sum += i;
    }
  }

  return sum;

}

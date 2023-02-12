#include <stdio.h>

void stars(int k) {

  for (int i = 0; i < k; i++) {

    printf(" ");

  }

  printf("\nPrinted %d spaces.\n", k);

}

int main () {

  printSpace(10);

}

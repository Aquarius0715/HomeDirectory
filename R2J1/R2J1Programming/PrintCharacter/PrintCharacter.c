#include <stdio.h>

void A1 (int a, char b) {

  for (int i = 0; i < a; i++) {

    printf("%c\n", b);

  }

}

int main () {

  int a = 10;
  char b = 'h';

  A1(a, b);

  return 0;
  

}

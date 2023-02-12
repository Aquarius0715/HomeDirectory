#include <stdio.h>

void dec2bin2(int a, char b[]) {

  for (int i = 0; a > 0; i++) {

    b[i] = a % 2; a /= 2;
    
  }

}

int main () {

  int k;
  char b[10];

  dec2bin2(8, b);

  for (k = 0; k < 4; k++) printf("%c", b[k]);

  printf("\n");
  
  return 0;

}

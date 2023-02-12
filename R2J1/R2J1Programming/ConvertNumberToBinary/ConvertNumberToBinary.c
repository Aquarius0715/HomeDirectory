#include <stdio.h>

void dec2bin1 (int a,int b[]) {

  for (int i = 0; a > 0; i++) {

    b[i] = a % 2; a /= 2;
    
  }
  
}

int main () {

  int k, b[3];
  dec2bin1(5, b);
  
  for (k = 0; k < 3; k++) printf("%d", b[k]);

  printf("\n");

  return 0;

}

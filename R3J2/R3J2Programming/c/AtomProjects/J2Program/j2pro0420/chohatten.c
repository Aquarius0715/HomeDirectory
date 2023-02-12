#include <stdio.h>

void getBinary(int n, int a[]) {

  for (int i = 0; n > 0 ; i++) {

    a[i] = n % 2; n /= 2;
    
  }
  
}

int main () {

  int binary[1000];
  int eightBinary[1000];

  getBinary(3, binary);

  for (int i = 0; binary[i] != '\0'; i++) {

    printf("%d", binary[i]);
    
  }
  printf("\n");

  for (int i = 10; 1 ; i++) {

    

  }

}

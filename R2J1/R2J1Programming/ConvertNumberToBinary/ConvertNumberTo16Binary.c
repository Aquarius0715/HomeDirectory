#include <stdio.h>

int dec2hex(int a, char b[]) {

  int length;
  char data[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (length = 0; a > 0; length++) {
    b[length] = data[a % 16]; a /= 16;    
  }
  
  return length;
  
}

int main () {

  int k, N;
  char b[100];
  N = dec2hex(165, b);
  for (k = N - 1; k >= 0; k--) {
    printf("%c", b[k]); 
  }
  printf("\n");

  return 0;
  
}

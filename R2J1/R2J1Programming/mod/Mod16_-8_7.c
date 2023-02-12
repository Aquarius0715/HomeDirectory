#include <stdio.h>

void convertBinaryFromDecimal(int n) {
  int binary[4];
  for (int i = 0; i < 4; i++) { 
    binary[i] = n % 2; n /= 2;
  }
  for (int i = 3; i > -1; i--) {
    printf("%d", binary[i]);
  }
  printf("\n");
}

int main () {
  for (int i = 7; i > -9; i--) {
    if (i < 0) {
      printf("%d    %d    ", i + 16, i);
      convertBinaryFromDecimal(i + 16);
    } else {
      printf("%d    %d    ", i - 16, i);
      convertBinaryFromDecimal(i);
    }
  }
  return 0;
}

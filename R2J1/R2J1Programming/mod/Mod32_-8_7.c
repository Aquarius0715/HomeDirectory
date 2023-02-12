#include <stdio.h>
#define N 6

void convertBinaryFromDecimal(int n) {
  int binary[N];
  for (int i = 0; i < N; i++) { 
    binary[i] = n % 2; n /= 2;
  }
  for (int i = N - 1; i > -1; i--) {
    printf("%d", binary[i]);
  }
  printf("\n");
}

int main () {
  for (int i = 7; i > -9; i--) {
    if (i < 0) {
      printf("%d    %d    ", i + 32, i);
      convertBinaryFromDecimal(i + 32);
    } else {
      printf("%d    %d    ", i - 32, i);
      convertBinaryFromDecimal(i);
    }
  }
  return 0;
}

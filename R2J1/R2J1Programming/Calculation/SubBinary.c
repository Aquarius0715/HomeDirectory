#include <stdio.h>
#define N 4

void arrayPrint(int a[]) {
  for (int i = 0; i < N; i++) {
    printf("%d", a[i]);
  }
}

void addBinary(int a[], int b[]) {
  int k = 0;
  for (int i = N - 1; i > -1; i--) {
    switch(a[i] + b[i] + k) {
    case 0:
      b[i] = 0; k = 0; break;
    case 1:
      b[i] = 1; k = 0; break;
    case 2:
      b[i] = 0; k = 1; break;
    case 3:
      b[i] = 1; k = 1; break;
    }
  }
}

void convertBinaryFromDecimal(int n, int a[]) {
  for (int i = N - 1; i > -1; i--) {
    a[i] = n % 2; n /= 2;
  }
}

void convertBinaryToComplement(int a[]) {
  for (int i = 0; i < N; i++) {
    a[i] = !a[i];
  }
  int b[N] = {0, 0, 0, 1};
  addBinary(b, a);
}

int main() {
  int a[N];
  int b[N];
  convertBinaryFromDecimal(3, a);
  convertBinaryFromDecimal(2, b);
  convertBinaryToComplement(b);
  addBinary(a, b);
  arrayPrint(b);
  return 0;
}

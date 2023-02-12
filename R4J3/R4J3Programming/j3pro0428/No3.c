#include <stdio.h>

int calc(int n);

int main() {
  int n;
  printf("Type Stages: ");
  scanf("%d", &n);

  printf("Conbination is %d\n", calc(n));
  return 0;
}

int calc(int n) {
  if (n == 1 || n == 2) {
    return n;
  }
  if (n == 3) {
    return 4;
  }
  return calc(n - 1) + calc(n - 2) + calc(n - 3);
}

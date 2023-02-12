#include <stdio.h>

int calc(int n);

int main() {
  int n;
  printf("Type Rows: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("%d \n", calc(i));
  }
  return 0;
}

int calc(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return calc(n - 1) + calc(n - 2);
}

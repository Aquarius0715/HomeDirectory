#include <stdio.h>

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a <= 1 || b >= 10000) {
    printf("無効な値です。\n");
    return 1;
  }
  if ((a * b) % 2 == 0) {
    printf("Even\n");
  } else {
    printf("Odd\n");
  }
  return 0;
}

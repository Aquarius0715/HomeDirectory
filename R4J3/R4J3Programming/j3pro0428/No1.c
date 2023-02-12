#include <stdio.h>

int f(int x) {
  if (x == 3) {
    return 11;
  }
  return 2 * f(x - 2) + 3;
}

int main() {
  printf("%d\n", f(7));
  return 0;
}

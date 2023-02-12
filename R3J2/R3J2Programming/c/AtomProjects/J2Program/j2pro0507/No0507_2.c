#include <stdio.h>

int compareNum(int x, int y, int z) {

  for (int i = 0; 1 ; i++) {
    if (x - i < 0) {
      return x;
    } else if (y - i < 0) {
      return y;
    } else if (z - i < 0) {
      return z;
    }
  }
}

int main () {
  printf("Minimam num is %d\n", compareNum(-10, 89, -100));
  return 0;
}

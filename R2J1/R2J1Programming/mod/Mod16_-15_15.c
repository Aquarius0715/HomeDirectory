#include <stdio.h>

int main () {

  for (int i = 8; i > -8; i--) {
    if (i < 0) {
      printf("%d    %d\n", 16 + i, i);
    } else {
      printf("%d    %d\n", i - 16, i);
    }
  }
  return 0;
}

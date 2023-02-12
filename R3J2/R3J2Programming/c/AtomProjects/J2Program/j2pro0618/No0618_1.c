#include <stdio.h>

int main () {
  char string[10];
  for (int i = 0; i < 10; i++) {
    scanf("%c", &string[i]);
  }
  printf("--------------------------");
  for (int i = 9; i >= 0; i--) {
    printf("%c", string[i]);
  }
  printf("\n");
  return 0;
}

#include <stdio.h>

int getLengthOfString(char string[]);

int main () {
  printf("%d\n", getLengthOfString("Hello"));
  return 0;
}

int getLengthOfString(char string[]) {
  for (int i = 0; 1 ; i++) {
    if (string[i] == '\0') {
      return i;
    }
  }
}

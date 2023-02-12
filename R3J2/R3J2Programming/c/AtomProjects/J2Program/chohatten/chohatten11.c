#include <stdio.h>

void printStringShifting(char string[]);

int main () {
  printStringShifting("I want to play the guiter.");
  return 0;
}

void printStringShifting(char string[]) {
  for (int i = 0; string[i] != '\0'; i++) {
    for (int ii = 0; ii < i; ii++) {
      printf(" ");
    }
    printf("%c\n", string[i]);
  }
}

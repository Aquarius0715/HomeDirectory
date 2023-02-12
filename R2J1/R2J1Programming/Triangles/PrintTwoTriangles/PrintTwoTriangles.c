#include <stdio.h>

int main() {

  int lineCount = 0;
  int spaceCount = 4;
  int stoneCount = 0;

  while (lineCount < 5) {
    for (int ii = 0; ii < 2; ii++) {
    for (int i = 0; i < spaceCount; i++) {
      printf(" ");
    }
    for (int i = 0; i < 5 - spaceCount; i++) {
      printf("*");
    }
    }
    printf("\n");
    lineCount++;
    spaceCount--;
  }
}

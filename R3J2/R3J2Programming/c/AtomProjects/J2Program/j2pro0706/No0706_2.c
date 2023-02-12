#include <stdio.h>

int getNumberOfWords(char string[]);

int main () {
  int words = getNumberOfWords("I want to eat hotdog because it is not dog.");
  printf("%d\n", words);
  return 0;
}

int getNumberOfWords(char string[]) {
  int count = 0;
  for (int i = 0; 1 ; i++) {
    if (string[i] == ' ') {
      count++;
    }
    if (string[i] == '\0') {
      count++;
      return count;
    }
  }
}

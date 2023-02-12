#include <stdio.h>

char words[256][64];

void getWordFromString(char string[]);
void printStringToReverseWord();
int getLength(char string[]);

int main () {
  getWordFromString("Do you like hotdog? I like hotdog because it is not dog.");
  printStringToReverseWord();
  return 0;
}

void getWordFromString(char string[]) {
  int i = 0;
  int wordCount = 0;
  int indexCount = 0;
  while (string[i] != '\0') {
    if (string[i] == ' ') {
      wordCount++;
      i++;
      indexCount = 0;
      continue;
    }
    words[wordCount][indexCount] = string[i];
    i++;
    indexCount++;
  }
}

int getLength(char string[]) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}

void printStringToReverseWord() {
  int i = 0;
  while (words[i][0] != '\0') {
    int ii = getLength(words[i]);
    while (ii >= 0) {
      printf("%c", words[i][ii]);
      ii--;
    }
    i++;
    printf(" ");
  }
  printf("\n");
}

#include <stdio.h>

int wordCompare(char word1[], char word2[]);

int main () {

  char word1[] = "book";
  char word2[] = "bookk";

  int result = wordCompare(word1, word2);

  if (result == 1) {
    printf("%s > %s\n", word1, word2);
  } else if (result == 0) {
    printf("%s = %s\n", word1, word2);
  } else if (result == -1) {
    printf("%s < %s\n", word1, word2);
  }
  return 0;
}

int wordCompare(char word1[], char word2[]) {
  int i = 0;
  while (word1[i] != '\0' || word2[i] != '\0') {
    if (word1[i] == word2[i]) {
      i++;
      continue;
    }
    if (word1[i] > word2[i]) {
      return 1;
    }
    if (word1[i] < word2[i]) {
      return -1;
    }
  }
  return 0;
}

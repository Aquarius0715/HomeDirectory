#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  char **address;
  char **vowels;
  char **consonants;
  char **domain;

  return 0;
}

void init(char **pt) {
  srand((unsigned) time (NULL));
  pt = (char**)malloc(sizeof(char*) * 10000); 
}

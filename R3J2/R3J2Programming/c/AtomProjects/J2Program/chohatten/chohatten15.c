#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET 26

int randomMinToMax(int min, int max); //random.c
void init();                          //this
void encrypt();                       //this

char data[ALPHABET];
char original[256] = "nationalinstituteofkisarazucollege";
char encrypted[256];

int main () {
  init();
  encrypt();
  printf("%s\n", data);
  printf("%s\n", encrypted);
  return 0;
}

void encrypt() {
  int i = 0;
  while (original[i] != '\0') {
    encrypted[i] = data[original[i] - 'a'];
    i++;
  }
}

void init() {
  char flag[128];
  srand((unsigned) time (NULL));
  for (int i = 0; i < 128; i++) {
    flag[i] = 0;
  }
  for (int i = 0; i < ALPHABET; i++) {
    char rnd = randomMinToMax('a', 'z');
    if (flag[rnd]) {
      i--;
      continue;
    }
    data[i] = rnd;
    flag[rnd] = 1;
  }
}

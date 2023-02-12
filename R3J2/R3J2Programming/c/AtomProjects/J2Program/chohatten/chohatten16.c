#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET 26

int randomMinToMax(int min, int max); //random.c
void init();                          //this
void encrypt();                       //this

char data[ALPHABET];
char data1[ALPHABET];
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
    if (i % 2 == 0) {
      encrypted[i] = data[original[i] - 'a'];
    } else {
      encrypted[i] = data1[original[i] - 'a'];
    }
    i++;
  }
}

void init() {
  char flag[128];
  char flag1[128];
  srand((unsigned) time (NULL));
  for (int i = 0; i < 128; i++) {
    flag[i] = 0;
    flag1[i] = 0;
  }
  for (int i = 0; i < ALPHABET; i++) {
    char rnd = randomMinToMax('a', 'z');
    char rnd1 = randomMinToMax('a', 'z');
    if (flag[rnd] || flag1[rnd1]) {
      i--;
      continue;
    }
    data[i] = rnd;
    data1[i] = rnd1;
    flag[rnd] = 1;
    flag[rnd1] = 1;
  }
}

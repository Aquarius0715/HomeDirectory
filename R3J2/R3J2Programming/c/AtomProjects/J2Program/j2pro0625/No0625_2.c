#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 200

int random_min_to_max(char min, char max);
int init();
int isContains(int i);
void printRandomCharacter();

int chara[NUM];

int main() {
  init();
  printRandomCharacter();
  return 0;
}

int init() {
  srand((unsigned) time (NULL));
  for (int i = 0; i < NUM; i++) {
    chara[i] = 0;
  }
}

int random_min_to_max(char min, char max) {
  return rand() % (max - min) + min + 1;
}

int isContains(int i) {
  return chara[i];
}

void printRandomCharacter() {
  for (int i = 0; i < 5; i++) {
    int rnd = random_min_to_max('A', 'Z');
    if (isContains(rnd)) {
      i--;
      continue;
    }
      printf("%c\n", rnd);
      chara[rnd] = 1;
  }
}

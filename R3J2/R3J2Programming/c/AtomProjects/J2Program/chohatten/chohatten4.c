#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init();
void generateNumber();

int flag[100000];

int main () {
  init();
  generateNumber();
  return 0;
}

void init() {
  srand((unsigned) time (NULL));
  for (int i = 0; i < 100000; i++) {
    flag[i] = 0;
  }
}

int isContains(int n) {
  return flag[n];
}

void generateNumber() {
  for (int i = 0; i < 100000; i++) {
    int rnd = rand() % 100000;
    if (isContains(rnd)) {
      i--;
      continue;
    }
    int n1 = rnd / 10000;
    int n2 = rnd % 10000;

    printf("%5d: 0438-0%d-%d\n",i, n1, n2);
    flag[rnd] = 1;
  }
}

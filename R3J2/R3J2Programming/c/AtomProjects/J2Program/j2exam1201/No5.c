#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomMinToMax(int min, int max);

int main() {

  int card[5][5];
  int flag[100];

  srand((unsigned) time (NULL));

  for (int i = 0; i < 100; i++) {
    flag[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int rnd = randomMinToMax(1, 99);
      if (flag[rnd] == 0) {
        card[i][j] = rnd;
        flag[rnd] = 1;
      } else {
        j--;
        continue;
      }
    }
  }

  card[2][2] = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int randomMinToMax(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200
#define M 200000

int takarakuji(int vol, int no);

int history[N][M] = {};

int isExists(int a[N][M], int vol, int no) {
  if (a[vol][no] == 1) {
    return 1;
  }
  return 0;
}

void getNumber() {

  for (int i = 0; i < 100; i++) {

  int vol = rand() % 100 + 1;
  int no = rand() % 100000 + 100000;

        if (isExists(history, vol, no)) {
          i--;
          continue;
        } else {
          printf("ID: %d Vol: %d No: %d Amount: %d\n",i + 1, vol, no, takarakuji(vol, no));
          history[vol][no] = 1;
        }
      }
    }

int main(void) {

  srand((unsigned)time(NULL));

  getNumber();

  return 0;
}

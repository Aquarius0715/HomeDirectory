#include <stdio.h>

int calcDozen(int pencils);

int main () {

  int pencils = 24;

  printf("%d honn ha %d da-su desu.\n", pencils, calcDozen(pencils));

  return 0;

}

int calcDozen(int pencils) {

  int dozen = pencils / 12;

  if ((dozen % 12) != 0) {
    dozen++;
  }

  return dozen;

}

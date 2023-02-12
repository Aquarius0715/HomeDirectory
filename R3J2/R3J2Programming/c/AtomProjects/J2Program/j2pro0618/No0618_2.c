#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_min_to_max(int min, int max) {

  return rand() % (max - min) + min + 1;

}

int main () {
  srand((unsigned) time(NULL));
  printf("%c\n", random_min_to_max('a', 'z'));
  return 0;
}

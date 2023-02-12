#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_seed();
int random_min_to_max(int min, int max);
int Random(int x);

int main () {

  init_seed();

  char password[8];

  for (int i = 0; i < 8; i++) {
    switch (Random(3)) {
      case 0:
        password[i] = random_min_to_max('A', 'Z');
        break;
      case 1:
        password[i] = random_min_to_max('a', 'z');
        break;
      case 2:
        password[i] = random_min_to_max('0', '9');
        break;
    }
  }

    printf("Your password is %s\n", password);

    return 0;
}

void init_seed() {
  srand((unsigned) time (NULL));
}

int random_min_to_max(int min, int max) {
  return rand() % (max - min) + min + 1;
}

int Random(int x) {
  return rand() % x;
}

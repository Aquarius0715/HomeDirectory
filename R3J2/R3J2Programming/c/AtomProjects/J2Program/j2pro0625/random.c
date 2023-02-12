#include <stdlib.h>
#include <time.h>

int random(int integer) {
  return rand() % integer;
}

int dice() {
  return rand() % 6 + 1;
}

int randomMinToMax(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int initSeed() {
  srand((unsigned) time (NULL));
}

int generateRandomCharacter() {
  switch (random(4)) {
    case 0:
    return randomMinToMax('A', 'Z');

    case 1:
    return randomMinToMax('a', 'z');

    case 2:
    return randomMinToMax('0', '9');

    case 3:
    if (random(2) == 1) {
      return '@';
    } else {
      return '$';
    }

    default:
    return -1;
  }
}

int generatePassword(char password[]) {
  for (int i = 0; i < 8; i++) {
    switch (random(4)) {
      case 0:
      password[i] = randomMinToMax('A', 'Z');
      break;

      case 1:
      password[i] = randomMinToMax('a', 'z');
      break;

      case 2:
      password[i] = randomMinToMax('0', '9');
      break;

      case 3:
      if (random(2) == 1) {
        password[i] = '@';
      } else {
        password[i] = '$';
      }
      break;

      default:
      return 1;
    }
  }
  return 0;
}

int getPassword(char password[]) {
  for (int i = 0; i < 8; i++) {

  }
  return 0;
}

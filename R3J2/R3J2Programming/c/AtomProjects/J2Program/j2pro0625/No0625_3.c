#include <stdio.h>

char getRandomCharacter();
int sumOeda();
void initSeed();
int random(int integer);
int randomMinToMax(int min, int max);

int main() {
  initSeed();
  int sum = sumOeda();
  printf("%d kai oeda ga demasita.\n", sum);
  return 0;
}

char getRandomCharacter() {
  switch (random(2)) {
    case 0:
    return randomMinToMax('0', '9');

    case 1:
    return randomMinToMax('a', 'z');
  }
}

int sumOeda() {
  int count = 0;
  int sum = 0;
    for (int i = 0; i < 1000000000; i++) {
      char c = getRandomCharacter();
      if (count == 0 && c == 'o') {
        //printf("%c", c);
        count++;
        continue;
      } else if (count == 1 && c == 'e') {
        //printf("%c", c);
        count++;
        continue;
      } else if (count == 2 && c == 'd') {
        //printf("%c", c);
        count++;
        continue;
      } else if (count == 3 && c == 'a') {
        //printf("%c", c);
        sum++;
        count == 0;
        continue;
      }
      count = 0;
    }
  return sum;
}

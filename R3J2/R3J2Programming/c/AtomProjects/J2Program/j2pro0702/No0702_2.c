#include <stdio.h>

#define ARRAY_SIZE 100

char generateRandomCharacter();
void setCharacter(char array[ARRAY_SIZE]);
void dispArray(char array[ARRAY_SIZE]);
void convertBigCapital(char array[ARRAY_SIZE]);

int randomMinToMax(int min, int max);

int main () {
  char array[ARRAY_SIZE];
  setCharacter(array);
  convertBigCapital(array);
  dispArray(array);
  return 0;
}

char generateRandomCharacter() {
  return randomMinToMax('a', 'z');
}

void setCharacter(char array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = generateRandomCharacter();
  }
}

void dispArray(char array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%c", array[i]);
  }
  printf("\n");
}

void convertBigCapital(char array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (array[i] == 'k') {
      array[i] = 'K';
    }
  }
}

#include <stdio.h>

#define ARRAY_SIZE 10

void setNumber(int array[ARRAY_SIZE]);
void dispNumber(int array[ARRAY_SIZE]);
void doubleNumber(int array[ARRAY_SIZE]);

int main () {
  int array[ARRAY_SIZE];
  setNumber(array);
  printf("----------------------------------\n");
  dispNumber(array);
  doubleNumber(array);
  printf("----------------------------------\n");
  dispNumber(array);
  return 0;
}

void setNumber(int array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = i + 1;
  }
}

void dispNumber(int array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void doubleNumber(int array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] *= 2;
  }
}

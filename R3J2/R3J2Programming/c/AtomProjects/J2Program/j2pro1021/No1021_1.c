#include <stdio.h>

#define SIZE 10

int main () {
  int array[SIZE];
  int *pt = &array[0];

  for (int i = 0; i < SIZE; i++) {
    *(pt + i) = 0;
  }

  for (int i = 0; i < SIZE; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");

  return 0;
}

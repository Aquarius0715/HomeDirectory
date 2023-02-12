#include <stdio.h>
#include <stdlib.h>

int len(char* string);
void append(int *array, int size,  int elem);
int* init(int* array, int size, int elem);
void printArray(int* array, int size);
int getIntegerCount(int* array, int size);

int main(void) {
  char string[256];
  scanf("%s", string);
  int stringLength = len(string);

  int j = 0;
  int i = 1;
  int prefixSuffixArray[stringLength];

  init(prefixSuffixArray, stringLength, -1);
  prefixSuffixArray[0] = 0;

  while (getIntegerCount(prefixSuffixArray, stringLength) < stringLength) {
    if (string[j] == string[i]) {
      append(prefixSuffixArray, stringLength,  j + 1);
      i += 1;
      j += 1;
    } else {
      if (j == 0) {
	append(prefixSuffixArray, stringLength, 0);
	i += 1;
      }
      if (j != 0) {
	j = prefixSuffixArray[j - 1];
      }
    }
  }
  printArray(prefixSuffixArray, stringLength);
}

int len(char* string) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}

void append(int* array, int size,  int elem) {
  for (int i = 0; i < size; i++) {
    if (array[i] == -1) {
      array[i] = elem;
      return;
    }
  }
}

int* init(int* array, int size,  int elem) {
  for (int i = 0; i < size; i++) {
    array[i] = elem;
  }
  return array;
}

void printArray(int* array, int size) {
  printf("[%d", array[0]);
  for (int i = 1; i < size; i++) {
    printf(", %d", array[i]);
  }
  printf("]\n");
}

int getIntegerCount(int* array, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] != -1) {
      count++;
    } else {
      break;
    }
  }
  return count;
}

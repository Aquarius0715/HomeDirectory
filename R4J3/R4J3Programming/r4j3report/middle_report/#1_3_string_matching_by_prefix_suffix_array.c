#include <stdio.h>
#include <stdlib.h>

int len(char* string);
void append(int *array, int size,  int elem);
int* init(int* array, int size, int elem);
void printArray(int* array, int size);
int getIntegerCount(int* array, int size);

int* getPrefixSuffixArray(char* string, int* prefixSuffixArray);
int isEqual(char *str1, char *str2);

int main(void) {
  char string1[256];
  char string2[256];

  int stringLength = len(string2);
  int prefixSuffixArray[stringLength];
  
  scanf("%s", string1);
  scanf("%s", string2);
  
  getPrefixSuffixArray(string2, prefixSuffixArray);
  
  int i, j;

  i = 0;
  j = 0;
  while (string1[i] != '\0') {
    char buffer[stringLength];
    int k = 0;
    int equalCount = 0;
    while (string2[k] != '\0') {
      if (string1[i + k] != string2[k]) {
	if (k == 0) {
	  i++;
	  k = 0;
	  continue;
	} else {
	  i = prefixSuffixArray[k - 1];
	}
      }
      k++;
    }
    i++;
  }
  printf("不一致\n");
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

int* getPrefixSuffixArray(char* string, int* prefixSuffixArray) {
  int stringLength = len(string);
  int j = 0;
  int i = 1;

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
  return prefixSuffixArray;
}

int isEqual(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != '\0' || str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      if (i == 0) {
	return 0;
      } else {
	//	i = prefixSuffixArray[i - 1];
	continue;
      }
    }
    i++;
  }
  return 1;
}

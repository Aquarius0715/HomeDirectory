#include <stdio.h>

typedef struct {
  char string[128];
  char *prefix[128];
  char *suffix[128];
  int count;
} Data;

int length(char* str);
int equal(char* str1, char* str2);
void createStringTable(Data* array, int strCnt);

int main(void) {
  char string[] = "tiktik";
  const int strLen = length(string);
  Data array[strLen - 1] = {NULL};
  int i, j;
  for (i = 0; strLen < i; i++) {
    char string[32];
    Data newData;
    for (j = 0; j < i; j++) {
      buffer[j] = []
    }
  }
  return 0;
}

int length(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return 0;
}

int equal(char* str1, char* str2) {
  int i = 0;
  while (str1[i] != '\0' || str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}

void createStringTable(Data* array, int strCnt) {
  
}

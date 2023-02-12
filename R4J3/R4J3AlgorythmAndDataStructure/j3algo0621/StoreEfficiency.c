#include <stdio.h>
#include <stdlib.h>

typedef struct num {
  int Data;
  struct num *NextData;
} Number;

Number newNumber(int Data, Number *NextData);

int main() {
  int i, j, m;
  int N[] = {1, 24, 55, 25, 135, 24, 9, 12, 19, 33, 30,44, 21, 34, 90, 15, 13, 21, 34};
  Number *n;
  Number *L[10];

  for (i = 0; i < 10; i++) {
    L[i] = NULL;
  }

  for (i = 0; i < sizeof(N) / sizeof(N[0]); i++) {
    m = N[i] % 10;
    if (L[m] == NULL) {
      L[m] = *newNumber(N[i], NULL);
    } else {
      n = L[m];
      while (n ->NextData != NULL) {
	n = *(n ->NextData)
      }
      n -> NextData = (Number*) malloc (sizeof(Number));
      *(n -> NextData) = newNumber(N[i], NULL);
    }
  }
  return 0;
}

Number newNumber(int Data, Number *NextData) {
  Number n = {Data, NextData};
  return n;
}

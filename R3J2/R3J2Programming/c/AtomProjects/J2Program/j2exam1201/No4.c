#include <stdio.h>
#include <stdlib.h>

int main() {

//(1)
  int n;
  int *pt;

  srand(1201);

  printf("Type num: ");
  scanf("%d", &n);

  pt = (int *)malloc((sizeof(int)) * n);

  for (int i = 0; i < n; i++) {
    pt[i] = rand() % 10000;
    printf("%d ", pt[i]);
  }
  printf("\n");

//(2)
int c;
  for (int i = 0; i < n; i++) {
    int x = pt[i];
    if ((x % 2) == 0) {
      c++;
    }
  }
  printf("count = %d\n", c);

//(3)
int max = 0;
int sec = 0;
  for (int i = 0; i < n; i++) {
    if (max < pt[i]) {
      max = pt[i];
    }
  }

  int boolean = 0;
  for (int i = max - 1; boolean != 1; i--) {
    for (int j = 0; j < n; j++) {
      if (i == pt[j]) {
        sec = pt[j];
        boolean = 1;
      }
    }
  }

  printf("second max = %d\n", sec);

  free(pt);

  return 0;
}

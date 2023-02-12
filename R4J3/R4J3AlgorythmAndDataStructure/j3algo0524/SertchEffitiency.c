#include <stdio.h>

#define N 10

int main() {

  int i, j, k, I;
  int s[] = {1, 8, 18, 7, 9, 39 ,40 ,18 ,14 ,12};
  int l[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (i = 0; i < N; i++) {
    j = s[i] % 10;
    if (i + j < N) {
      k = i + j - 1;
    }
    if (i + j >= N) {
      k = i + j - N - 1;
    }
    if (l[k] == 0) {
      l[k] = s[i];
      continue;
    } else if (l[k] != 0 && l[k] == s[i]) {
      continue;
    }
  }

  for (i = 0; i < N; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
  
  for (i = 0; i < N; i++) {
    printf("%d ", l[i]);
  }
  printf("\n");
  
  return 0;
}

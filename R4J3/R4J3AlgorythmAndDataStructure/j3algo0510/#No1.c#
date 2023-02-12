#include <stdio.h>

#define N 50

int map[N];

int isContains(int map[], int element, int count) {
  for (int i = 0; i < count; i++) {
    if (map[i] == element) {
      return 1;
    }
  }
  return 0;
}

int calc(int n) {
  if (n == 0) {
    return 0;
  }
  int c = calc(n - 1) - n;
  if (c > 0) {
    if (!isContains(map, c, n)) {
      return c;
    }
  }
  return calc(n - 1) + n;
}

int main() {
  for (int i = 0; i < N; i++) {
    int c = calc(i);
    printf("%d %d\n", i, count);
    map[i] = c;
  }
  return 0;
}

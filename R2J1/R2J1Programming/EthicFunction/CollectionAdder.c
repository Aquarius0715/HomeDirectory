#include <stdio.h>

//参照だけ。書き換え禁止
int a[2][3] = {{0, 0, 1}, {0, 1, 1}};
int b[2][3] = {{0, 1, 0}, {1, 0, 1}};

int convertBinaryToIndex(int a, int b) {
  switch (a + b) {
  case 0:
    return 0; break;
  case 2:
    return 2; break;
  default:
    return 1; break;
  }
}

int add(int x[4], int y[4], int ans[4]) {
  int k = 0;
  for (int i = 3; i >= 0; i--) {
    int n = convertBinaryToIndex(x[i], y[i]);
    ans[i] = b[k][n];
    k = a[k][n];
  }
}

int display(int a[4]) {
  for (int i = 0; i < 4; i++) {


    printf("%d", a[i]);
  }
  return 0;
}

int main () {
  int x[4] = {1, 0, 1, 1};
  int y[4] = {0, 0, 0, 1};
  int ans[4];
  add(x, y, ans);
  printf("  "); display(x); printf("\n");
  printf("+)"); display(y); printf("\n------");
  printf("\n  "); display(ans); printf("\n");
  return 0;
}

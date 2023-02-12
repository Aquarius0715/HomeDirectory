#include <stdio.h>
#include "./ronri.h"

int FA_2(int a, int b, int c) {
  return OR(AND(NOT(a), AND(b, c)), AND(a, OR(b, c)));
}

int FA_1(int a, int b, int c) {
  return OR(AND(NOT(a), XOR(b, c)), AND(a, NOT(XOR(b, c))));
}

int hyouji(int a[4]) {
  for (int i = 3; i >= 0; i--) {
    printf("%d", a[i]);
  }
  return 0;
}

int main () {
  int a[4] = {1, 0, 1, 1};
  int b[4] = {1, 1, 1, 0};
  int c = 0;
  int ans[4];
  for (int i = 0; i < 4; i++) {
    ans[i] = FA_1(c, a[i], b[i]);
    c = FA_2(c, a[i], b[i]);
  }
  printf("  "); hyouji(a); printf("\n");
  printf("+)"); hyouji(b); printf("\n------");
  printf("\n  "); hyouji(ans); printf("\n");
  return 0;
}


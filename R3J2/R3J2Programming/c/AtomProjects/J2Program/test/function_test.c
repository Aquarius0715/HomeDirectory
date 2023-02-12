#include <stdio.h>

void func(int *sp);

int score = 10;
int *sp = &score;

int main() {
  printf("%d\n", score);
  func(sp);
  printf("%d\n", score);
  return 0;
}

void func(int *sp) {
  *sp = 100;
}

#include <stdio.h>

int main(void) {
  int L = 0;
  int x = 0;
  int allStone = 0;

  printf("底辺の数を入力してください。\n");

  scanf("%d", &x);

  while(L <= x) {
   int R = 0;
    while(R < L) {
      printf("*");
      R++;
      allStone++;
    }
    printf("\n");
    L++;
  }
  printf("全体の石の数: %d\n", allStone);
  printf("底辺の数: %d\n", x);

  return 0;
}

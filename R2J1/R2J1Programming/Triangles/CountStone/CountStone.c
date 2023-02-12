#include <stdio.h>

int main() {
  int x;
  int s = 0;

  printf("整数を入力してください\n");
  
  scanf("%d", &x);
  while(x > 0) {
    s += x;
    x--;
  }

  printf("石の個数は%d個です\n", s);

  return 0;

}

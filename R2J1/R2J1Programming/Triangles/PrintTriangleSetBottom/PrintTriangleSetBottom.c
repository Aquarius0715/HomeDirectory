#include <stdbool.h>
#include <stdbool.h>

int main() {

  int bottom = 0;
  int count = 0;
  int stone = 0;

  printf("底辺の数を入力してください。\n");

  scanf("%d", &bottom);

  while(count < bottom) {
    stone += bottom - count;
    count++;
  }

  printf("石の個数は %d です。\n", stone);

}

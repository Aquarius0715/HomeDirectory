#include <stdio.h>
#include <stdbool.h>

int main() {

  int allStone = 0;
  int stone = 0;
  int count = 0;

  printf("石の総数を入力してください。\n");
  scanf("%d", &allStone);
  stone = allStone;

  while(true) {
    if (allStone - count <= 0) {
      break;
    }

    count++;

    allStone -= count;
  }

  printf("%dこの石を使ってできるピラミッドの段数は %d 段です。\n", stone, count);
}

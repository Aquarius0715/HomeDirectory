#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main() {

  // 変数の宣言
  int num[N], max, i, j, k, temp;

  srand((unsigned) time(NULL));

  // 配列の初期化
  for (int i = 0; i < N; i++) {
    num[i] = rand() % 100 + 1;
  }

  // 降順にソート
  int c = 0;
  for (i = 0; i < N - 1; i++) {
    max = num[i];
    k = i;
    for (j = i + 1; j < N; j++) {
      if (num[j] > max) {
	max = num[j];
	k = j;
      }
    }
    temp = num[i];
    num[i] = num[k];
    num[k] = temp;
  }

  printf("Max Multiple: %d * %d * %d = %d\n", num[0], num[1], num[2], num[0] * num[1] * num[3]);
  
  return 0;
}

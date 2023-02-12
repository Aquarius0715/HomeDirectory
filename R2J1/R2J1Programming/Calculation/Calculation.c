#include <stdio.h>

int main() {

  int n1 = 0;
  int n2 = 0;

  printf("整数を入力してください。\n");

  while(1) {
    printf("\n");
    scanf("%d", &n1);
    if (n1 <= -999) {
      printf("-999以下の数が入力されました。計算を終了します。最後の数は %d でした。\n", n2);
      break;
    }

    printf("%d + %d = %d", n2, n1, n2 + n1);
    n2 += n1;
  }
}

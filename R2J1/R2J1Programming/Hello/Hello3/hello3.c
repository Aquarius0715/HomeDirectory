#include <stdio.h>

int main(void) {

  int n;

  printf("数を入力してください\n");

  scanf("%d", &n);

  printf("%dが入力されました\n", n);

  printf("\n");

  int count = 0;

  for (int i = 0; i < 5; i++) {
    printf("\n");
    for (int ii = 0; ii < count + 1; ii++) {
      printf("*");
    }
    count++;
  }

  printf("\n");

    return 0;
}

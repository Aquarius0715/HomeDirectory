#include <stdio.h>
#include <stdbool.h>

int main() {

  double root = 0.0;
  int n = 0;

  printf("求めたい平方根の数を入力してください。\n");
  scanf("%d", &n);

  while(true) {
    if (root * root >= n) {
      break;
    }

    root += 0.000001;
  }

  printf("「%d」の平方根の近似値は %f です。\n", n, root);

  return 0;
}

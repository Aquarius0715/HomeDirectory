#include <stdio.h>

int main () {
  int a, b, c;
  char str[101];

  scanf("%d", &a);
  scanf("%d %d", &b, &c);
  scanf("%s", str);

  if (a <= 1 && a >= 1000 || b <= 1 && b >= 1000 || c <= 1 && c>= 1000) {
    printf("無効な値です。\n");
  }

  printf("%d %s\n", a + b + c, str);
  return 0;
}

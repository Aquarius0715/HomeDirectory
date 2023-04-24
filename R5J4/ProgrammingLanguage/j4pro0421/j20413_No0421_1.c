#include <stdio.h>

typedef enum Boolean {
  FALSE,
  TRUE
} Boolean;

Boolean isContains3(int n);

int main(void) {
  int n = 0;
  while (n < 2 || n > 100000) {
	 printf("Type number(range 2-100000): ");
	 scanf("%d", &n);
  }
  for (int i = 1; i <= n; i++) {
	 printf("%d: ", i);
	 if (i % 3 == 0 || isContains3(i)) {
		printf("いまでしょ！\n");
	 }
	 else {
		printf("いつやるか？\n");
	 }
  }
  return 0;
}

Boolean isContains3(int n) {
  while (n != 0) {
	 if (n % 10 == 3) {
		return TRUE;
	 }
	 n /= 10;
  }
  return FALSE;
}

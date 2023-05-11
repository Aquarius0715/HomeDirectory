#include <stdio.h>

int main() {
  int n;
  int ima=0;
  printf("Input: ");
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
	 if (i%3 == 0) {
		printf("%d いまでしょ！\n", i);
		ima=1;
	 }
	 int m = i;
	 while (m!=0) {
		if (m%10 == 3) {
		  printf("%d いまでしょ！\n", i);
		  ima=1;
		  break;
		}
		m /= 10;
	 }
	 if (ima == 0) {
		printf("%d いつやるか？\n", i);
	 }
	 ima=0;
  }
}

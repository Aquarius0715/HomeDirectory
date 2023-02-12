#include <stdio.h>

#define N 8

int main () {

  int money[N] = {5000, 1000, 500, 100, 50, 10, 5, 1};
  int bal;
  int count;
  
  printf("Type your balance!\n");
  scanf("%d", &bal);

  for (int i = 0; i < N; i++) {
      int a = bal;
      
      for (count = 0; a > 0; count++) {
	if ((a - money[i]) < 0) {
	  break;
	}
	a -= money[i];
      }
      
    printf("%d -> %d\n", money[i], count);
    bal -= money[i] * count;
  }
}

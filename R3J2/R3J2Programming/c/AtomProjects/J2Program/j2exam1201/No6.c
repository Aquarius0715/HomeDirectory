#include <stdio.h>
#include <stdlib.h>

int get_blue(int n);
int get_white(int n);
int get_sum(int n);

int main() {

  printf("(1) (a)=%d, (i)=%d\n", get_blue(5), get_white(6));

  for (int i = 1; 1 ; i++) {
    if (get_blue(i) >= 36) {
      printf("(2)%d bannme\n", i);
      break;
    }
  }

  printf("(3)sum=%d\n", get_sum(30));
  
  int i

  return 0;
}

int get_blue(int n) {
  int sum = 1;
  for (int i = 1; i < (n + 1) / 2; i++) {
    sum += 1 * 2 + 1;
  }
  return sum;
}

int get_white(int n) {
  return get_sum(n) - get_blue(n);
}

int get_sum(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

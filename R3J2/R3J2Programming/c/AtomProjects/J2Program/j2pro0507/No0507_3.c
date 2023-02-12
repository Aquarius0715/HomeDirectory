#include <stdio.h>

int power(int x, int n) {
  
  int ans = 1;
  
  for (int i = 0; i < n; i++) {

    ans *= x;
    
  }

  return ans;

}

int main () {
  
  int x = 2;
  int n = 2;

  printf("%d no %d jouha %d desu\n", x, n, power(x, n));
  
  return 0;
  
}

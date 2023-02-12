#include <stdio.h>

//未完成

int super_power(int a, int b, int c) {

  int result = a;
  
  for (int i = 1; i < b; i++) {

    result *= a;
    
  }

  return result % c;
  
}

int main () {

  printf("%d\n", super_power(373, 6875, 273));
  
  return 0;
  
}

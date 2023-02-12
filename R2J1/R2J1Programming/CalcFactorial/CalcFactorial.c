#include <stdio.h>

int calcFactorial(int n) {

  int factorialNumber = 1;
  
  for (int i = 0; i < n; i++) {

    factorialNumber *= i + 1;
    
  }

  return factorialNumber;
  
}

int main () {

  while (1) {

    int n = 0;

    printf("number: "); scanf("%d", &n);

    if (n == 0) break;
    
    printf("The factorialNumber of %d is %d\n", n, calcFactorial(n));
    
  }

}

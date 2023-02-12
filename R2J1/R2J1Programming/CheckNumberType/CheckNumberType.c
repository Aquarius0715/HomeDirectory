#include <stdio.h>

int isEven (int n) {

  if (n % 2 == 0) {

    return 1;
    
  } else {

    return 0;
    
  }
  
}

int main () {

  int n = 0;

  printf("Type any number!!\nnumber: "); scanf("%d", &n);

  if (isEven(n)) {

    printf("The Integer %d is Even.\n", n);
    
  } else {

    printf("The Integer %d is Odd.\n", n);
    
  }

  return 0;
  
}

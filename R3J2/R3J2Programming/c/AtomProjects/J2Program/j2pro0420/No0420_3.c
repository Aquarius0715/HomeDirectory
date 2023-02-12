#include <stdio.h>

int main () {

  int n = 0;

  printf("type number!\n");
  
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int ii = 0; ii < i + 1; ii++) {

      printf("*");

    }

    printf("\n");
    
  }

}

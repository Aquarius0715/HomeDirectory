#include <stdio.h>

void star_space(int num);

int main () {

  int n = 0;
  
  printf("Type your number: ");
  scanf("%d", &n);

  for (int i = n; i > 0; i--) {

    star_space(i);
    
  }
  
  return 0;
  
}

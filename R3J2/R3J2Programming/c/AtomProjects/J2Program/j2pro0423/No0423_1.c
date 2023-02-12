#include <stdio.h>
#include <stdlib.h>

int main () {

  for (int i = 0; i < 100; i++) {

    printf("%d: %d\n",i + 1, rand());
    
  }
  
  return 0;
  
}

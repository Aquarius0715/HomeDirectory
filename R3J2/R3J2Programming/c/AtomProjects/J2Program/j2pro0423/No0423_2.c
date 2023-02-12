#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int n) {

    return rand() % n;

}

int main () {

    srand((unsigned)time(NULL));

  for (int i = 0; i < 10; i++) {

      printf("%d\n", Random(6));
    
  }
  
  return 0;
  
}

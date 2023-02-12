#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min = 23;
int max = 49;

int Random(int n) {

    return rand() % n + min;

}

int main () {

    srand((unsigned)time(NULL));

  for (int i = 0; i < 10; i++) {

      printf("%d\n", Random(max - min));
    
  }
  
  return 0;
  
}

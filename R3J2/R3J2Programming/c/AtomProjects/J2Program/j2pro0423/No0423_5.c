#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int result[6] = {0, 0, 0, 0, 0, 0};

int Random(int n) {

    return rand() % n + 1;

}

int main () {

    srand((unsigned)time(NULL));

    printf("start!\n");

  for (int i = 0; i < 60000000; i++) {

    if (Random(100) == 1) {

      result[1]++;
      
    } else {

      result[Random(6) - 1]++;
    
    }
  }

  printf("finish!\n");

  for (int i = 0; i < 6; i++) {

    printf("dice %d: %d\n", i + 1, result[i]);
    
  }
  
  return 0;
  
}

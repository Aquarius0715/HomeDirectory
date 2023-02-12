#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int n) {

    return rand() % n + 1;

}

int main () {

    srand((unsigned)time(NULL));
    printf("saikoro wo futte %d gademasita\n", Random(6));
  
    return 0;
  
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int count = 0;
  for (int j = 0; j < 1000000; j++) {
    int flag[365];
    for (int i = 0; i < 365; i++) {
      flag[i] = 0;
    }

    srand((unsigned) time (NULL));

    for (int i = 0; i < 40; i++) {
      int rnd = rand() % 365;
      if (flag[rnd] == 0) {
        flag[rnd] = 1;
        continue;
      } else {
        count++;
        continue;
      }
    }
  }
  printf("%d\n", count);
  printf("%lf\n%",(double) (count / 40000000.0) * 100); 
  return 0;
}

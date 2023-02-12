#include <stdio.h>int main () {
  int num = 0;
    int all = 0;
      while (1) {
        printf("Type number above 1\n");
        scanf("%d", &num);

        if (num > 0) {
          break;
        } else {
          printf("error: number is under zero\n");
          continue;
        }
      }
          for (int i = 1; i < num / 2 + 1; i++) {      all += i * 2;    }    printf("number is %d\n", all);    return 0;}

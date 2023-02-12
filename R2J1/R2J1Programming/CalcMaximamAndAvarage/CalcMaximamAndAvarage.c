#include <stdio.h>

int isMaximam(int max, int now) {

  if (now > max) {

    return 1;
    
  } else {

    return 0;
    
  }
  
}

int calcAvarage(int allScore, int count) {

  return allScore / count;
  
}

int main () {

  int allScore = 0;
  int maximam = 0;
  int count = 0;

  printf("Type any number!!\n");

  while (1) {

    int n = 0;

    printf("number: "); scanf("%d", &n);

    if (n == 0) break;

    allScore += n;

    if (isMaximam(maximam, n)) {

      maximam = n;
      
    }

    count++;
    
  }

  printf("The Maximam: %d, The Avarage: %d\n", maximam, calcAvarage(allScore, count));

}

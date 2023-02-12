#include <stdio.h>
#define N 10

void array_sort(int a[], int b[]) {

  int max = 0;
  int count = 0;

  for (int i = 0; i < N; i++) {

  for (int i = 0; i < N; i++) {

    if (a[i] > max) {

      max = a[i];
      
    }
    
  }

  int min = max;

  for (int i = 0; i < N; i++) {

    if (a[i] < min) {

      min = b[count];

      count++;

      a[i] = 99999999;
      
    }
    
  }

  }
  
}

int main () {

  int a[N] = {4, 2, 7, 1, 3, 9, 6, 8, 5, 0};
  int b[N];

  array_sort(a, b);

  for (int i = 0; i < N; i++) {

    printf("%d\n", b[i]);
  }

  return 0;
}

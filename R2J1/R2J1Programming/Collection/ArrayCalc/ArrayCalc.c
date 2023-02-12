#include <stdio.h>
#define N 6

void array_copy(int a[], int c[]) {
  for (int i = 0; i < N; i++) {
    c[i] = a[i];
  }
}

void array_print(int a[]) {
  int bool = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] != 0) bool = 1;
    if (!bool) continue;
    printf("%d", a[i]);
  }
  printf("\n");
}

void array_add(int a[], int b[], int c[]) {
  int k = 0;
  for (int i = 0; i < N; i++) {
    int n = a[N - i - 1] + b[N - i - 1] + k;
    if (n < 10) {
      c[N - i - 1] = n;
      k = 0;
    } else {
      c[N - i - 1] = n % 10;
      k = n / 10;
    }
  }
  printf("足し算の結果: "); array_print(c);
}

void array_sub(int a[], int b[], int c[]) {
  for (int i = 0; i < N; i++) {
    int index = N - i - 1;
    if (a[index] - b[index] < 0) {
      c[index] = a[index] + 10 - b[index];
      if (a[index - 1] == 0) {
	a[index - 1] = 9;
	a[index - 2] = a[index - 2] - 1;
      } else {
      a[index - 1] = a[index - 1] - 1;
      }     
    } else {
      c[index] = a[index] - b[index];     
    }  
  }
  printf("引き算の結果: "); array_print(c);
}

void array_multi(int a[], int b[], int c[]) {
  int x[N] = {0, 0, 0, 0, 0, 0};
  int y[N] = {0, 0, 0, 0, 0, 0};
  int z[N] = {0, 0, 0, 0, 0, 0};
  int k = 0;
  for (int i = 0; i < N; i++) {
    int n = b[N - i - 1];
    for (int ii = 0; ii < N; ii++) {
      int m = a[N - i - 1];
      if (n * m + k) 
    }
  }
}

int main () {

  int a[N] = {0, 0, 0, 4, 5, 6};
  int b[N] = {0, 0, 0, 1, 2, 3};
  int c[N] = {0, 0, 0, 0, 0, 0};

   /*    123 */
   /*  - 456 */
   /* ------ */
   /*    738 */
   /*   615  */
   /*  492   */
   /*--------*/
   /*  56088 */
      
  array_add(a, b, c);
  array_sub(a, b, c);

  return 0;
  
}

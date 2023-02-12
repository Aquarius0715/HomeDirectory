#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_num();
void set_num(int *pt, int n);
int get_max(int *pt, int n);
int get_sum(int *pt, int n);
void disp_matrix(int *pt, int n);
void init();

int main() {
  int n = get_num();
  int *matrix = (int *)malloc(sizeof(int) * n);

  init();

  set_num(matrix, n);

  disp_matrix(matrix, n);

  int max = get_max(matrix, n);
  int sum = get_sum(matrix, n);

  printf("max=%d\n", max);
  printf("sum=%d\n", sum);

  disp_matrix(matrix, n);

  return 0;
}


int get_num() {
  int n;
  printf("番号を入力してください -> ");
  scanf("%d", &n);
  return n;
}

void set_num(int *pt, int n) {
  for (int i = 0; i < n; i++) {
    pt[i] = rand() % 10;  
  }
}

int get_max(int *pt, int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (pt[i] > max) {
      max = pt[i];
    }
  }
  return max;
}

int get_sum(int *pt, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pt[i];
    pt[i] = sum;
  }
  return sum;
}

void disp_matrix(int *pt, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", pt[i]);
  }
  printf("\n");
}

void init() {
  srand((unsigned) time (NULL));
}

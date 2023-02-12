#include <stdio.h>
#include <stdlib.h>

int get_num();
void get_points(int n, int *pt);
void disp_point(int n, int *pt);

int main() {
  int n = get_num();
  int *point = (int *)malloc(sizeof(int)*(n + 1));

  get_points(n, point);

  disp_point(n, point);

  return 0;
}

int get_num() {
  int n;
  printf("人数を入力してください -> ");
  scanf("%d", &n);
  return n;
}

void get_points(int n, int *pt) {
  for (int i = 0; i < n; i++) {
    int m;
    printf("%d人目の得点を入力してください。 -> ", i + 1);
    scanf("%d", &m);
    pt[i] = m;
  }
}

void disp_point(int n, int *pt) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    printf("%d人目: %d 点\n", i + 1, pt[i]);
    sum += pt[i];
  }
}

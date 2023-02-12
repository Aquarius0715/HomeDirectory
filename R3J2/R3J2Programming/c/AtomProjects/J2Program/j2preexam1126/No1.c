#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_num();
void set_array(int *pt, int size);
void print_array(int *pt, int size);
int get_sum(int *pt, int size);
double get_avg(int *pt, int size);
void print_rev(int *pt, int size);
int get_sec(int *pt, int size);
void init();

int main() {

  init();

  int size = get_num();
  int *array = (int *) malloc((sizeof(int)) * size);

  set_array(array, size);
  print_array(array, size);

  double avg = get_avg(array, size);
  printf("avg is %lf\n", avg);

  print_rev(array, size);

  int sec = get_sec(array, size);
  printf("sec is %d\n", sec);

  free(array);

  return 0;
}

int get_num() {
  int n;
  printf("Type array size: ");
  scanf("%d", &n);
  return n;
}

void set_array(int *pt, int size) {
  for (int i = 0; i < size; i++) {
    pt[i] = rand() % 1000; 
  }
}

void print_array(int *pt, int size) {
  printf("array is ");
  for (int i = 0; i < size; i++) {
    printf("%d ", pt[i]);
  }
  printf("\n");
}

int get_sum(int *pt, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += pt[i];
  }
  return sum;
}

double get_avg(int *pt, int size) {
  double avg = 0.0;
  int sum = get_sum(pt, size);
  avg = (double) sum / (double) size;
  return avg;
}

void print_rev(int *pt, int size) {
  printf("rev -> ");
  for (int i = (size - 1); i >= 0; i--) {
    printf("%d ", pt[i]);
  }
  printf("\n");
}

int get_sec(int *pt, int size) {
  int max = pt[0];
  int sec;

  for (int i = 0; i < size; i++) {
    if (max < pt[i]) {
      sec = max;
      max = pt[i];
    } else {
      continue;
    }
  }
  return sec;
}

void init() {
  srand((unsigned) time (NULL));
}

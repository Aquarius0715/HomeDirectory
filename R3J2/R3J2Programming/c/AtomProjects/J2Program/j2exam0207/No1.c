#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void setData(int x[]);
void dispData(int x[]);
void swap(int *a, int *b);
void bubble_sort_asc(int array[]);

int main(void)
{
  int array[NUM];

  setData(array);
  dispData(array);

  bubble_sort_asc(array);
  dispData(array);

  return 0;
}

void setData(int x[])
{
  int i;

  srand(207);
  
  for (i=0; i<NUM; i++) {
    x[i] = rand()%100;
  }
  
}

void dispData(int x[])
{
  int i;
  
  for (i=0; i<NUM; i++) {
    printf("[%d] = %2d\n", i, x[i]);
  }
  printf("\n");
}

void bubble_sort_asc(int array[])
{
  int i;
  for (i = 0; i < NUM - 1; i++) {
    int j;
    for (j = NUM - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        swap(&array[j], &array[j - 1]);
      }
    }
  }
}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}


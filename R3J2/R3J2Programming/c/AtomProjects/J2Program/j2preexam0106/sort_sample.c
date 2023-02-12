#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void swap(int *a, int *b);
void initialize(int array[]);
void disp_array(int array[]);

void straight_sort_asc(int array[])
{
  int i, j;
  int min_index;
  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if(array[j]<array[min_index]) {
	    min_index = j;
      }
    }
    swap(&array[i], &array[min_index]);
  }
}

void straight_sort_desc(int array[]) {
  int i, j;
  int min_index;
  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if(array[j]>array[min_index]) {
	    min_index = j;
      }
    }
    swap(&array[i], &array[min_index]);
  }
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

void bubble_sort_desc(int array[]) {
  for (int i = 0; i < NUM - 1; i++) {
    for (int j = NUM - 1; j > i; j--) {
      if (array[j] > array[j - 1]) {
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

int main(void)
{
  int array[NUM];

  initialize(array);
  disp_array(array);

  bubble_sort_asc(array);
  disp_array(array);

  printf("min: %d, sec: %d\n", array[0], array[1]);
  
  return 0;
}

void initialize(int array[])
{
  int i;
  
  srand(0);

  for (i=0; i<NUM; i++) {
    array[i] = rand()%100;
  }
}

void disp_array(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("%d\n", array[i]);
  }
  printf("\n");

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];

  initialize(array);
  //disp_array(array);

  sort(array);
  disp_array(array);
  
  return 0;
}

void initialize(int array[])
{
  int i;
  
  srand((unsigned) time (NULL));

  for (i=0; i<NUM; i++) {
    array[i] = rand()%1000;
  }
}

void disp_array(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("%3d: %d\n", i + 1, array[i]);
  }
  printf("\n");

}

void sort(int array[])
{
  int i, j;
  int min_index;
  int change = 0;
  int compare = 0;

  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if(array[j] > array[min_index]) {
	    min_index = j;
        change++;
      }
      compare++;
    }
    swap(&array[i], &array[min_index]);
  }
}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

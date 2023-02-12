#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void initialize(int array[]);
void disp_array(int array[]);
void bubbleSort(int array[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];

  initialize(array);
  disp_array(array);

   bubbleSort(array);
  disp_array(array);
  
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

void bubbleSort(int array[])
{
  int minIndex;
  int compare = 0;
  int change = 0;

  for (int i = 0; i < NUM - 1; i++) {
    for (int j = NUM - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        swap(&array[j], &array[j - 1]);
        change++;
      }
      compare++;
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

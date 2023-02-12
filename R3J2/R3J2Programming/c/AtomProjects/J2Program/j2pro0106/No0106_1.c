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
  //disp_array(array);

   bubbleSort(array);
  //disp_array(array);

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

void bubbleSort(int array[])
{
  int minIndex;
  int count = 0;

  int i;
  for (i = 0; i < NUM - 1; i++) {
    minIndex = i;
    int j;
    for (j = i + 1; j < NUM; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
      count++;
    }
    swap(&array[i], &array[minIndex]);
  }
  printf("SORT END. COUNT = %d\n", count);
}

void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void setData(int x[]);
void dispData(int x[]);
void sort(int x[]);

int main(void)
{
  int array[NUM];

  setData(array);
  dispData(array);

  /* ここに単純選択ソート（降順）を書く */
  sort();

  dispData(array);

  return 0;
}

void setData(int x[])
{
  int i;

  srand(204);
  
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

void sort(int x[])
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

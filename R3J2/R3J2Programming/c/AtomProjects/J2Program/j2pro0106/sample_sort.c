#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];

  initialize(array);
  disp_array(array);

  sort(array);
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

void sort(int array[])
{


}

void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

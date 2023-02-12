#include <stdio.h>
#include <stdlib.h>

#define NUM 20000000

int main(void)
{
  double *array;
  
  array = (double *)malloc(sizeof(double)*NUM);

  array[0] = 123.456;
  array[NUM-1] = 987.789;

  printf("array[0]=%f\n", array[0]);
  printf("array[NUM-1]=%f\n", array[NUM-1]);

  free(array);
  
  return 0;
}

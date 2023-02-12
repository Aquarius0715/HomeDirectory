#include <stdio.h>

#define NUM 5

int main(void)
{
  int i;
  int vc[NUM] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = &vc[0];

  for (i=0; i<NUM; i++) {
  printf("[%p]: vc[%d] = %d   ptr[%d] = %d   *(ptr+%d) = %d\n",
           &vc[i], i, vc[i], i, ptr[i], i, *(ptr+i) );
  }

  ptr = &vc[2];
  printf("(1) %d\n", *ptr);
  printf("(2) %d\n", *(ptr+1));
  printf("(3) %d\n", *ptr+1);

  return 0;
}

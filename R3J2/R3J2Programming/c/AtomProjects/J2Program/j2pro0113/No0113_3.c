#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM 100

void initialize(char array[]);
void disp_array(char array[]);
void bubbleSort(char array[]);
void swap(char *a, char *b);
int randomMinToMax(int min, int max);


int main(void)
{
  char array[NUM + 1];

  initialize(array);
  //disp_array(array);

   bubbleSort(array);
  disp_array(array);
  return 0;
}

void initialize(char array[])
{
  int i;
  
  srand((unsigned) time (NULL));

  for (i=0; i<NUM; i++) {
    array[i] = randomMinToMax('a', 'z');
  }
}

void disp_array(char array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("%3d: %c\n",i + 1, array[i]);
  }
  printf("\n");

}

void bubbleSort(char array[])
{
  int minIndex;
  int compare = 0;
  int change = 0;

  int i;
  for (i = 0; i < NUM - 1; i++) {
    int j;
    for (j = NUM - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        swap(&array[j], &array[j - 1]);
        change++;
      }
      compare++;
    }
  }
}

void swap(char *a, char *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int randomMinToMax(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

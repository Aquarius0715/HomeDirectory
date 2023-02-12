#include <stdio.h>
#include <stdlib.h>

#define NUM 500
#define MAX 1000

void initialize(int data[]);
void disp_top10(int data[]);
void swap(int *a, int *b);
int calc_sum(int data[]);
int straight_sort_desc(int data[], int size);
int calc_chuochi(int data[]);
int calc_saihinchi(int data[]);

int main(void)
{
  int data[NUM];
  double median;
  int mode;
  int prime_ct;
  
  srand(207);
  
  initialize(data);

  printf("(1)sum = %d\n", calc_sum(data));

  straight_sort_desc(data, NUM);
	
  disp_top10(data);

  printf("(3)chuochi = %d\n", calc_chuochi(data));

  printf("(4)saihinchi = %d\n", calc_saihinchi(data));
  
  return 0;
}

void initialize(int data[])
{
  int i;
  
  for (i=0; i<NUM; i++) {
    data[i] = rand()%MAX;
  }
}

void disp_top10(int data[])
{
  int i;
  
  for (i=0; i<10; i++) {
    printf("%2d %3d\n", i, data[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int calc_sum(int data[]) {
  int sum = 0;
  for (int i = 0; i < NUM; i++) {
    sum += data[i];
  }
  return sum;
}

int straight_sort_desc(int data[], int size) {
  int i, j;
  int min_index;
  for (i=0; i<size-1; i++) {
    min_index = i;
    for (j=i+1; j<size; j++) {
      if(data[j]<data[min_index]) {
	min_index = j;
      }
    }
    swap(&data[i], &data[min_index]);
  }
  return min_index;
}

int calc_chuochi(int data[]) {
  int chuochi;
  if ((NUM % 2) == 0) {
    chuochi = (data[NUM / 2] + data[(NUM / 2) + 1]) / 2;
  } else {
    chuochi = data[NUM / 2];
  }
  return chuochi;
}

int calc_saihinchi(int data[]) {
  int count[MAX];
  int saihinchi;
  for (int i = 0; i < MAX; i++) {
    count[i] = 0;
  }
			      
  for (int i = 0; i < NUM; i++) {
    count[data[i]]++;
  }
  saihinchi = straight_sort_desc(count, MAX);
  return saihinchi;
}

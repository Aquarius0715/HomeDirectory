#include <stdio.h>
#include <stdlib.h>

#define NUM 100

int count_k(char str[]);
int randomMinToMax(int min, int max); //random.c

int main(void)
{
  char str[NUM+1];

  srand(731);

  int i = 0;
  while (i < NUM) {
    str[i] = randomMinToMax('a', 'z');
    i++;
  }

  printf("%s\n", str);
  printf("count: %d\n", count_k(str));

  return 0;
}

int count_k(char str[])
{
  int i = 0;
  int count = 0;
  while (i < NUM) {
    if (str[i] == 'k') {
      count++;
    }
    i++;
  }
  return count;
}

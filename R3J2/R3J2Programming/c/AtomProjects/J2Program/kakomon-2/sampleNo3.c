#include <stdio.h>

int calc_sum_csv(char csv[]);
//int getSize(char string[]);
//int perseInt(char num[]);

int main(void)
{
  char csv1[]="1,2,3,4,5";
  char csv2[]="11,22,33,44,55";
  char csv3[]="1,3,10,562,12,34,2,987,2345";

  printf("sum = %d\n", calc_sum_csv(csv1));

  return 0;
}

int calc_sum_csv(char csv[])
{
  int i = 0;
  int sum = 0;
  while (csv[i] != '\0') {
    if (csv[i] == ',') {
      i++;
      continue;
    }
    sum += csv[i] - '0';
    i++;
  }
  return sum;
}

/*

int calc_sum_csv(char csv[])
{
  int result = 0;
  int i = 0;
  while (csv[i] != '\0') {
    char num[5];
    int ii = 0;
    while (csv[i] != ',') {
      num[ii] = csv[i];
      i++;
      ii++;
    }
    result += perseInt(num);
    i++;
  }
  return result;
}

int getSize(char string[]) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}

int perseInt(char num[]) {
  int result = 0;
  int i = getSize(num);
  int k = 1;
  while (i >= 0) {
    result = (num[i] - '0') * k;
    k *= 10;
    i--;
  }
  return result;
}
*/

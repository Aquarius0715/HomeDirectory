#include <stdio.h>

void dispString(char str[]);
int countLength(char str[]);
void dispStringReverse(char str[]);
void dispOnlyNumber(char str[]);

int main(void)
{
  char str[] = "zyx98da4k5w4x097ltqdrax2cba";
  int len;

  printf("(1)\n");
  dispString(str);


  printf("(2)\n");
  len = countLength(str);
  printf("%d\n", len);


  printf("(3)\n");
  dispStringReverse(str);


  printf("(4)\n");
  dispOnlyNumber(str);


  return 0;
}


/*******
 * (1)
 *******/
void dispString(char str[])
{
  printf("%s\n", str);
}


/*******
 * (2)
 *******/
int countLength(char str[])
{
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}


/*******
 * (3)
 *******/
void dispStringReverse(char str[])
{
  for (int i = countLength(str); i >= 0; i--) {
    printf("%c", str[i]);
  }
  printf("\n");
}


/*******
 * (4)
 *******/
void dispOnlyNumber(char str[])
{
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= '0' && str[i] <= '9') {
      printf("%c", str[i]);
    }
    i++;
  }
  printf("\n");
}

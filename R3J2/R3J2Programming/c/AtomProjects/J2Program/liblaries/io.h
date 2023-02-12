#include <stdio.h>

void println(char string[]) {

  printf("%s\n", string);

}

int scan_integer(char string[]) {

  int num;

  printf("%s:", string);
  scanf("%d", &num);

  return num;

}

double scan_double(char string[]) {

  double num;

  printf("%s:", string);
  scanf("%df", &num);

  return num;

}

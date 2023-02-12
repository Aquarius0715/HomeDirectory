#include <stdio.h>

void println(char string[]) {

  printf("%s\n", string);

}

int scan_integer(char msg[]) {

  int num;

  printf("%s:", msg);
  scanf("%d", &num);

  return num;

}

double scan_double(char msg[]) {

  double num;

  printf("%s:", msg);
  scanf("%df", &num);

  return num;

}

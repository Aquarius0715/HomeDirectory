#include "io.h"

int main () {

  println("test!!!");

  int n = scan_integer("Type your number: ");

  printf("This is %d\n", n);

  char c[];

  scan_string("Type your string: ", c);

  printf("%s\n", c);

  return 0;

}

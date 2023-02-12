#include <stdio.h>

int main () {

  int a = 5000;
  int b = 12340;
  int all = 0;

  for (int i = 5000; i < 12340 + 1; i++) {
    for (int ii = 2; ii < 5000 + 1; ii++) {
      if (i % ii == 0) {
	break;
      }
    }
  }
  return 0;
}

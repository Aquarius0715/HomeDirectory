#include <stdio.h>

int main () {

  int all = 0;

  for (int i = 5000; i <= 12340; i++) {
    for (int ii = 2; ii < i ; ii++) {
      if (ii == i - 1) {
	all += i;
	break;
      }
      if (i % ii == 0) {
	break;
      }
    }
  }
  printf("goukei ha %d\n", all);
  return 0;
}

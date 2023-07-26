#include <stdio.h>

int findDigitCount(int n) {
  int digitCount = 0;
  while (n != 0 || digitCount == 0) {
	 n /= 10;
	 digitCount ++;
  }
  return digitCount;
}

int main(void) {
  printf("%d\n", findDigitCount(0));
  printf("%d\n", findDigitCount(7));
  printf("%d\n", findDigitCount(1234));
  return 0;
}

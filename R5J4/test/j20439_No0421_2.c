#include <stdio.h>
#include <stdlib.h>

typedef enum Sign {
  PLUS,
  MINUS
} Sign;

int main(void) {
  char string[] = "1, 45, 678, 98, -1";
  // char string[] = "1,   45,  678, 98, abc, -1";
  int sum = 0;

  int digit = 1;
  Sign sign = PLUS;
  int temp = 0;
  for (int i = (sizeof(string) / sizeof(char)) - 2; i >= 0; i--) {
	 if (string[i] == ' ') {
		continue;
	 }
	 else if (string[i] == '-') {
		sign = MINUS;
		continue;
	 }
	 else if (string[i] == ',') {
		if (sign == MINUS) {
		  temp *= -1;
		}
		sum += temp;
		temp = 0;
		digit = 1;
		sign = PLUS;
		continue;
	 }
	 else if (string[i] < '0' || string[i] > '9') {
		printf("Input Error\n");
		exit(1);
	 }
	 temp += (string[i] - '0') * digit;
	 digit *= 10;
	 if (i == 0) {
		if (sign == MINUS) {
		  temp *= -1;
		}
		sum += temp;
	 }
  }
  printf("sum=%d\n", sum);
  return 0;
}

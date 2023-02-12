#include <stdio.h>

void decimal2binary(char num);
int get_num();

int main () {

  int num = get_num();

  decimal2binary(num);

  return 0;

}

void decimal2binary(char num) {

  int binary[8];

  for (int i = 0; i < 8; i++) {

    binary[7 - i] = num % 2;
    num /= 2;

  }

  for (int i = 0; i < 8; i++) {
    printf("%d", binary[i]);
  }

  printf("\n");

}

int get_num() {

  int num;

  while (1) {

  printf("Type number!!: ");
  scanf("%d", &num);

    if (num < 0) {
      continue;
    } else {
      break;
    }
  }

  return num;

}

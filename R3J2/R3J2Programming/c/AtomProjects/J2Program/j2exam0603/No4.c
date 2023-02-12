#include "io.h"
#include "check.h"

void init(int array[]) {
  for (int i = 0; i < 10; i++) {
    array[i] = -1;
  }
}

int main() {
  int num;

  int array[10];
  init(array);

  while (1) {
    num = scan_integer("Type your number!! ");

    if (!(checkInteger(num, 0, 2147483647))) {
      println("number error!!");
      continue;
    } else {
      break;
    }
  }

  for (int i = 0; i < 10; i++) {
    array[9 - i] = num % 10; num /= 10;
  }

  int index = 0;

  for (int i = 1; i <= 10; i++) {
    if (array[i - 1] == -1) {
      continue;
    }
    index ++;
    if ((index % 3) == 0) {
      printf(",");
    }
    printf("%d", array[i - 1]);
  }

  printf("\n");

  return 0;
}

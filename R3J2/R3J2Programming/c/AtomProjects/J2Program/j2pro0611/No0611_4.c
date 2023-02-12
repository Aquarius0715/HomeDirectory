#include "io.h"
#include "check.h"

void init(int array[]);
int get_num();

int main() {
  int num = get_num();
  int array[10];
  init(array);

  for (int i = 0; i < 10; i++) {
      if (num == 0) {
        break;
      }
      array[i] = num % 10;
      num /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (array[9 - i] == -1) {
      continue;
    }
    printf("%d", array[9 - i]);
    if (i % 3 == 0 && i != 9) {
      printf(",");
    }
  }

  printf("\n");

  return 0;
}

void init(int array[]) {
  for (int i = 0; i < 10; i++) {
    array[i] = -1;
  }
}

int get_num() {
  int num;
  while (1) {
    num = scan_integer("Type your number!! ");

    if (!(checkInteger(num, 0, 2147483647))) {
      println("number error!!");
      continue;
    } else {
      break;
    }
  }
  return num;
}

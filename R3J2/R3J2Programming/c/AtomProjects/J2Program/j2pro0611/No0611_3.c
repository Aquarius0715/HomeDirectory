#include "io.h"
#include "check.h"

int is_contains_3(int num);
int is_baisu(int num);

int main () {

  int num;

  while (1) {
    num = scan_integer("Type your number!! ");

    if (!(checkInteger(num, 1, 100000))) {
      println("number error!!");
      continue;
    } else {
      break;
    }
  }

  for (int i = 0; i < num; i++) {

    printf("iD:%d ", i + 1);

  if (is_baisu(i + 1) || is_contains_3(i + 1)) {
    println("imadesyo!!!");
  } else {
    println("ituyaruka???");
  }
}
  return 0;
}

int is_baisu(int num) {
  if ((num % 3) == 0 && num != 0) {
    return 1;
  } else {
    return 0;
  }
}

int is_contains_3(int num) {
  for (int i = 0; i < 10; i++) {
    if ((num % 10) == 3) {
      return 1;
    }
    num /= 10;
  }
  return 0;
}

#include <stdio.h>

void printLemon();

int main () {
  for (int i = 0; i < 10; i++) {
    printLemon();
  }
  return 0;
}

void printLemon() {
  printf("Lemon!!\n");
}

#include <stdio.h>



int getNumber() {
  long num;
  printf("Type your number: ");
  scanf("%ld", &num);

  return num;
}

void toString(long num, char string[]) {
  int i = 0;
  while (num != 0) {
    string[i] = num % 10 + '0';
    num /= 10;
    i++;
  }
}

void swapString(char string) {
  char str_data[256];
  int i = 0;
  while (string[i] != '0') {
    str_data[i] = string[i];
    i++;
  }
  i = 255;
  int ii = 0;
  while (i <= 0) {
    while (str_data[i] == '\0') {
      i--;
    }
    string[ii] = str_data[i];
    i--;
  }
}

int main () {
  char string[256];
  long num = getNumber();
  toString(num, string);
  swapString(string);
  printf("%s\n", string);
return 0;

}

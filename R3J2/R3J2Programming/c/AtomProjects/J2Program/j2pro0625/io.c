#include <stdio.h>

void println(char string[]) {
  printf("%s\n", string);
}

int scanInteger(int min, int max) {
  int num;
  while (1) {
    if (num >= min && num <= max) {
      return num;
    }
    printf("Type your number!: ");
    scanf("%d", &num);
  }
}

double scanDouble(int min, int max) {
  double num;
  while (1) {
    if (num >= min && num <= max) {
      return num;
    }
    printf("Type your number!: ");
    scanf("%lf", &num);
  }
}

long scanLong(long min, long max) {
  long num;
  while (1) {
    if (num >= min && num <= max) {
      return num;
    }
    printf("Type your number!: ");
    scanf("%ld", &num);
   }
}

short scanShort(int min, int max) {
  short num;
  while (1) {
    if (num >= min && num <= max) {
      return num;
    }
    printf("Type your number!: ");
    scanf("%d", &num);
  }
}

char scanChar(int min, int max) {
  char num;
  while (1) {
    if (num >= min && num <= max) {
      return num;
    }
    printf("Type your number!: ");
    scanf("%c", &num);
  }
}

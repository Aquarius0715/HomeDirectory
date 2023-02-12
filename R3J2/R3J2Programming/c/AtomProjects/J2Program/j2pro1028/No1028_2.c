#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLOMN 11

void resistor_phone_number(int phone_numbers[ROW][COLOMN]);
void enable();
void show_phone_numbers(int phone_numbers[ROW][COLOMN]);
void commands(char str[], int phone_numbers[ROW][COLOMN]);
int get_length(char str[]);
int is_equal(char str_1[], char str_2[]);

int main() {
  int phone_numbers[ROW][COLOMN] = {};

enable(phone_numbers);

  return 0;
}

void resistor_phone_number(int phone_numbers[ROW][COLOMN]) {
  int i, j;
  long phone_number;

  for (i = 0; i < ROW; i++) {
    printf("Type phone number (%d): ", i + 1);
    scanf("%ld", &phone_number);
    printf("%ld\n", phone_number);
    for (j = (COLOMN - 1); j >= 0; j--) {
      phone_numbers[i][j] = phone_number % 10;
      phone_number /= 10;
    }
  }
}

void enable(int phone_numbers[ROW][COLOMN]) {
  char cmd[64];

  while (1) {
    printf("PhoneBook: ");
    scanf("%s", cmd);
    commands(cmd, phone_numbers);
  }
}

void disable() {
  //TODO save
  printf("Bye\n");
  exit(0);
}

void show_phone_numbers(int phone_numbers[ROW][COLOMN]) {
  int i, j;
  
  for (i = 0; i < ROW; i++) {
    printf("(%d) ", i + 1);
    for (j = 0; j < COLOMN; j++) {
      if (j == 3 || j == 7) {
        printf("-");
      }
      printf("%d", phone_numbers[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void commands(char str[], int phone_numbers[ROW][COLOMN]) {
  if (is_equal("resi", str) == 1) {
    resistor_phone_number(phone_numbers);
  } else if (is_equal("show", str) == 1) {
    show_phone_numbers(phone_numbers);
  } else if (is_equal("quit", str) == 1) {
    disable();
  }
}

int get_length(char str[]) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

int is_equal(char str_1[], char str_2[]) {
  int i = 0;
  while (str_1[i] != '\0') {
    if (str_1[i] != str_2[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}

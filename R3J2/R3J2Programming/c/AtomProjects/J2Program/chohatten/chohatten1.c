/*
created by Masaki Kitano
*/
//TODO totyuudesu
#include <stdio.h>

#define BIT 32

void convertBinary(int num, int hosu, int binary[BIT]);
int isPalindrome(int num);

int main () {
  int num;
  printf("Type number!: ");
  scanf("%d", &num);
  if (isPalindrome(num)) {
    printf("kaibunnsuu\n");
  } else {
    printf("tigau\n");
  }
  return 0;
}

void convertBinary(int num, int hosu, int binary[BIT]) {
  for (int i = BIT - 1; i >= 0; i--) {
    binary[i] = num % hosu;
    num /= hosu;
  }
}

int isEqual(int a[BIT], int b[BIT]) {
  for (int i = 0; i < BIT; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}

int isPalindrome(int num) {
  int ans1[BIT];
  int ans2[BIT];

  for (int i = 0; i < 3; i++) {
    int number[BIT];

    switch (i) {
      case 0:
      convertBinary(num, 2, number);
      break;
      case 1:
      convertBinary(num, 8, number);
      break;
      case 2:
      convertBinary(num, 10, number);
      break;
    }

    int index = 0;
    for (int i = 0; i < BIT; i++) {
      while (number == 0) {
        i++;
      }
      ans1[index] = number[i];
    }
    for (int i = 0; i = index; i++) {
      ans2[i] = number[BIT - 1 - i];
    }

    if (!isEqual(ans1, ans2)) {
      return 0;
    }
  }
  return 1;
}

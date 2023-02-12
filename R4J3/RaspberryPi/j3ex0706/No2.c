#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

void display(int n);

const int seg_bit[6][7] = {
  {0, 0, 0, 0, 1, 1, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
};
const int pin[8] = {
  4, 5, 6, 12, 13, 16, 17, 19
};
const int button_pin = 20;

int main(void) {
  int flag = 0;
  int i;
  int rnd = 0;
  
  if (wiringPiSetupGpio() == -1) {
    return 1;
  }

  for (i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], 0);
  }
  pinMode(button_pin, INPUT);

  while (1) {
    if (digitalRead(button_pin) == LOW) {
      flag = !flag;
      while (digitalRead(button_pin) == LOW);
    }
    if (flag == 0) {
      rnd = rand() % 6;
    }
    display(rnd);
    printf("%d\n", flag);
  }
  return 0;
}

void display(int n) {
  int j;
  for (j = 0; j < 7; j++) {
    digitalWrite(pin[j], seg_bit[n][j]);
  }
  delay(10);
}

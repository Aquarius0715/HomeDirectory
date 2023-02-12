#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

void display(int n);

const int seg_bit[2][7] = {
  {0, 0, 0, 0, 1, 1, 0}, // 1
  {1, 1, 1, 1, 1, 1, 0}  // 0
};
const int pin[8] = {
  17, 19, 4, 5, 6, 12, 13, 16
};
const int button_pin = 20;

int main(void) {
  int flag = 0;
  int i;
  
  if (wiringPiSetupGpio() == -1) {
    return 1;
  }

  for (i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], 0);
  }
  pinMode(button_pin, INPUT);

  while (1) {
    if (digitalRead(button_pin) == 1) {
      if (flag == 0) {
	flag = 1;
      } else {
	flag = 0;
      }
      while (digitalRead(button_pin) == 1);
    }
    display(flag);
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

#include <wiringPi.h>

#define EASY 1000
#define NORMAL 500
#define HARD 100

void disolkay(int n);

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
  int i, j;
  int difficulty = EASY;
  if (wiringPiSetupGpio() == -1) {
    return 1;
  }
  for (i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    disitalWrite(pin[i], 0);
  }
  pinMode(button_pin, INTPUT);
  while (1) {
    for (j = 0; j < difficulty; j++) {
      if (digitalRead(button_pin) == HIGH) {
	for (j = 0; j < 3; j++) {
	  display(1);
	  delay(500);
	}
	return 0;
      }
      display(1);
    }
    display(0);
  }
}

void display(int n) {
  int j;
  for (j = 0; j < 7; j++) {
    digitalWrite(pin[j], seg_bit[n][j]);
  }
  delay(10);
}

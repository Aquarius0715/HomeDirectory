#include <wiringPi.h>

#define GPIO17 17

int main(void) {
  /** init wiringPi **/
  if(wiringPiSetupGpio() == -1) return 1;

  /** Set GPIO14 pin output mode **/
  pinMode(GPIO17, OUTPUT);

  /** Repeat led pulse **/
  while (1) {
    digitalWrite(GPIO17, 0);
    delay(500);
    digitalWrite(GPIO17, 1);
    delay(500);
  }
  return 0;
}

#include <wiringPi.h>
#include <stdio.h>

#define GPIO18 18

int main(void) {
  if (wiringPiSetupGpio() == -1) {
    return 1;
  }
  pinMode(GPIO18, INPUT);
  while (1) {
    printf("%d\n", digitalRead(GPIO18));
    delay(1000);
  }
  return 0;
}

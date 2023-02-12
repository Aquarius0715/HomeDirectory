#include "J2FestivalGroup3.h"

byte checkSensor(byte pin) {
  if (digitalRead(pin) == HIGH) {
    while (digitalRead(pin) != LOW);
    return 1;
  } else {
    return 0;
  }
}

byte sleep(unsigned long startMillis, long interval) {
  unsigned long currentMillis = millis();
  if ((currentMillis - startMillis) >= interval) {
    return 0;
  } else {
    return 1;
  }
}

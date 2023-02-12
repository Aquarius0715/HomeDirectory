#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

/*７セグメントディスプレイを制御するための構造体*/
typedef struct {
  byte PIN_SER;
  byte PIN_LATCH;
  byte PIN_CLK;

  /*７セグメントディスプレイのデータ*/

      const byte pinData[12] = {
        B01111110,
        B00110000,
        B01101101,
        B01111001,
        B00110011,
        B01011011,
        B01011011,
        B01110010,
        B01111111,
        B01111011,
        B01001111,
        B00000000
      };

  void setup() {
    pinMode(PIN_SER, OUTPUT);
    pinMode(PIN_LATCH, OUTPUT);
    pinMode(PIN_CLK, OUTPUT);
  }

  void disp(int n) {
    digitalWrite(PIN_LATCH, LOW);
    shiftOut(PIN_SER, PIN_CLK, LSBFIRST, pinData[n]);
    digitalWrite(PIN_LATCH, HIGH);
  }

  void dispRandom() {
    int rnd = rand() % 10;
    digitalWrite(PIN_LATCH, LOW);
    shiftOut(PIN_SER, PIN_CLK, LSBFIRST, pinData[rnd]);
    digitalWrite(PIN_LATCH, HIGH);
  }
} SevenSegment;

#endif //SEVENSEGMENT_H

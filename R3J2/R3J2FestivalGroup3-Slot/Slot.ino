#include "J2FestivalGroup3.h"

Result confirmRoll() {
    int rnd = rand() % PROBABILITY;
    Result result;
    if (rnd == 0) {
      int rnd1 = rand() % 10;
      result.seg_1 = rnd1;
      result.seg_2 = rnd1;
      result.seg_3 = rnd1;
      return result;
    } else {
      result.seg_1 = rand() % 10;
      result.seg_2 = rand() % 10;
      result.seg_3 = rand() % 10;
      return result;
    }
}

int startSlot() {

  Result result = confirmRoll();

  for (int i = 0; i < (TIME_OF_ROLL - (INTERVAL_OF_ROLL * 2)); i++) {
    seg_1.dispRandom();
    seg_2.dispRandom();
    seg_3.dispRandom();
    unsigned long startMillis = millis();
    while (sleep(startMillis, 100)) {
      waiting += checkSensor(SLOT_SENSOR);
    }
  }

  seg_1.disp(result.seg_1);
  
  for (int i = 0; i < INTERVAL_OF_ROLL; i++) {
    seg_2.dispRandom();
    seg_3.dispRandom();
    unsigned long startMillis = millis();
    while (sleep(startMillis, 100)) {
      waiting += checkSensor(SLOT_SENSOR);
    }
  }

  seg_2.disp(result.seg_2);
  
  for (int i = 0; i < INTERVAL_OF_ROLL; i) {
    seg_3.dispRandom();
    unsigned long startMillis = millis();
    while (sleep(startMillis, 100)) {
      waiting += checkSensor(SLOT_SENSOR);
    }
  }

  seg_3.disp(result.seg_3);

  if (result.seg_1 == result.seg_2 == result.seg_3) {
   return result.seg_1 * MAGNIFICATION;
  } else {
    return 0;
  }
}

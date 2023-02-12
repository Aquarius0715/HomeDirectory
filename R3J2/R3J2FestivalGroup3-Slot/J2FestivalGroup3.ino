#include "J2FestivalGroup3.h"
/*7セグを司る構造体の宣言*/
SevenSegment seg_1 = {{1, 2, 3, 4, 5, 6, 7}};
SevenSegment seg_2 = {{8, 9, 10, 11, 12, 13, 14}};
SevenSegment seg_3 = {{15, 16, 17, 18, 19, 20, 21}};

/*スロットを司る根幹変数*/
int score;         /*獲得スコア*/
int waiting;       /*残りのスロット回転数*/

void setup() {
  score = 0;
  waiting = 0;
  
  srand((unsigned) time (NULL));
  pinMode(SLOT_SENSOR, INPUT);

}

void loop() {
  waiting += checkSensor(SLOT_SENSOR);
  while (waiting != 0) {
    score += startSlot();
    waiting--;
  }
}

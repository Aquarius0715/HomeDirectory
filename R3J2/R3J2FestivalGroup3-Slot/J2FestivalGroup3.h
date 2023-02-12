/*ヘッダーの重複防止の記述*/
#ifndef J2FESTIVALGROUP3_H
#define J2FESTIVALGROUP3_H

/*インクルード*/
#include <stdlib.h>
#include <time.h>
#include <LiquidCrystal.h>
#include "SevenSegment.h"

/*スロットの根幹定数*/
#define PROBABILITY 2       /*確率を記述。1/x となるようにxの値を確定させる。*/
#define MAGNIFICATION 10    /*スロットが当たった時のポイントの倍率。*/
#define TIME_OF_ROLL 60     /*スロットの一回転の時間。msで記述。*/
#define INTERVAL_OF_ROLL 10 /*スロットの出目確定の間隔。msで記述。*/

/*Arduino制御の根幹定数*/
#define SLOT_SENSOR 0       /*当たり穴の光センサのピン*/

/*extern宣言*/
extern SevenSegment seg_1;
extern SevenSegment seg_2;
extern SevenSegment seg_3;
extern int score;
extern int waiting;

/*スロットの出目を他に渡すための構造体*/
typedef struct {
  int seg_1;
  int seg_2;
  int seg_3;
} Result;

/*プロトタイプ宣言*/
Result confirmRoll();
int startSlot();
byte checkSensor(byte pin);
byte sleep(unsigned long startMillis, long interval);

#endif //J2FESTIVALGROUP3_H

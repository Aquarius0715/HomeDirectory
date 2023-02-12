#include "J2FestivalGroup3.h"

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void initLCD() {
  lcd.begin(16, 2);
  lcd.clear();
}

void printScore() {
  lcd.setCursor(0, 0);
  lcd.print("Your Score   : %d", score);
}

void printWaiting() {
  lcd.setCursor(0, 1);
  lcd.print("Your Waiting : %d", waiting);
}

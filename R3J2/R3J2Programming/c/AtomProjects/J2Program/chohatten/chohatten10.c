#include <stdio.h>

/*
配列の大きさを定義
*/
#define STR_SIZE 13 //21奥の10桁 + カンマ3桁

/*
変数を定義
*/
char string[STR_SIZE];//文字列操作をする配列
char result[STR_SIZE];//最終的な結果を代入する配列

/*
メイン関数
*/
int main () {
  int num = -1;

  while (1) {
    if (num >= 0 && num <= 2147483647) {
      break;
    }
    printf("Type your number: ");
    scanf("%d", &num);
  }

/*
整数データを文字列化、3桁ごとにカンマを入れる処理
*/
  for (int i = 12; i >= 0; i--) {
    if (i == 9 || i == 5 || i == 1) {
      string[i] = ',';
      continue;
    }
    string[i] = num % 10 + 48;
    num /= 10;
  }

/*
無駄な桁を削除する処理
*/
  for (int i = 0, boolean = 0; i < STR_SIZE; i++) {
    if (!boolean) {
      if (string[i] == '0' || string[i] == ',') {
        string[i] = '\0';
        continue;
      }
      boolean = 1;
    }
  }

/*
行詰めして最終結果を格納する処理
*/
  for (int i = 0, index = 0; i < STR_SIZE; i++) {
    if (string[i] == '\0') {
      continue;
    }
    result[index] = string[i];
    index++;
  }

  printf("%s\n", result);

  return 0;
}

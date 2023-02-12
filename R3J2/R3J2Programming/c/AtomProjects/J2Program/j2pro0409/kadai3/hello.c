/*
ヘッダーファイル
*/
#include <stdio.h>

/*
メイン関数。この中の処理が実行されていく。
*/
int main () {

/*
変数宣言
*/
  int num = 0; //32bit整数

//whileループ
  int i = 0;//繰り返しの回数を数える変数。
  while (i < 10) { //10回繰り返す。
    num += i;//numに値を足していく。
    i++;//回数をプラスする。
  }

  //結果を出力
  printf("1 kara 10 madeno goukeiha %d desu\n", num);

  //正常終了を示すために0を返す。
  return 0;
}

#include <stdio.h>

/*
配列の大きさを定義
*/
#define PASS_SIZE 8

/*
プロトタイプ宣言
*/
void init();                         //this
void generatePassword2();            //this
int isContains(int num);             //this
void initSeed();                     //random.c
int randomMinToMax(int min, int max);//random.c

/*
変数を宣言
*/
char password[PASS_SIZE]; //パスワードを保存する配列の宣言
char data[64];            //アルファベット、数字、記号のデータ

/*
メイン関数
*/
int main () {
  init();             //ランダムの種の初期化
  generatePassword2();//ランダムパスワードの生成関数
  return 0;
}

/*
プログラム起動時に行う初期化
*/
void init() {
  int i = 0;
  for (char c = 'A'; c <= 'Z'; c++, i++) {
    data[i] = c;
  }
  for (char c = 'a'; c <= 'z'; c++, i++) {
    data[i] = c;
  }
  for (char c = '0'; c <= '9'; c++, i++) {
    data[i] = c;
  }
  data[i] = '@';
  data[i + 1] = '$';
  initSeed();
}

/*
文字の重複を確認する関数
*/
int isContains(int num) {
  if (data[num] == -1) {
    return 1;
  }
  return 0;
}

/*
ランダムパスワード生成関数
*/
void generatePassword2() {
  for (int i = 0; i < 8; i++) {
    int rnd = randomMinToMax(0, 63);
    if (isContains(rnd)) {
      i--;
      continue;
    }
    printf("%c", data[rnd]);
    data[rnd] = -1;
  }
  printf("\n");
}

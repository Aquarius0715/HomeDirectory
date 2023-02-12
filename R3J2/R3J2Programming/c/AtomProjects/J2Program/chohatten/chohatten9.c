#include <stdio.h>

/*
配列の大きさを定義
*/
#define ASCII_SIZE 128

/*
プロトタイプ宣言
*/
void initData();                     //this
void initAscii();                    //this
void init();                         //this
int calcStatistic();                 //this
int isContains(int num);             //this
void printResult();                  //this
void initSeed();                     //random.c
int randomMinToMax(int min, int max);//random.c

/*
変数の宣言
*/
char data[64];        //アルファベット、数字、記号データ
int ascii[ASCII_SIZE];//インデックスをアスキーコードに対応させた

/*
メイン関数
*/
int main () {
  init();         //プログラム起動時の初期化処理
  calcStatistic();//確率を計算する関数
  printResult();  //結果を出力する関数
  return 0;
}

/*
アルファベット、数字、記号データの初期化
*/
void initData() {
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
}

/*
配列の初期化
*/
void initAscii() {
  for (int i = 0; i < ASCII_SIZE; i++) {
    ascii[i] = 0;
  }
}

/*
プログラム起動時の初期化関数
*/
void init() {
  initSeed();
  initData();
  initAscii();
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
指定回数パスワードを生成し、確率を調べる関数
*/
int calcStatistic() {
  for (int i = 0; i < 100000; i++) {
    initData();
    for (int i = 0; i < 8; i++) {
      int rnd = randomMinToMax(0, 63);
      if (isContains(rnd)) {
        i--;
        continue;
      }
      ascii[data[rnd]]++;
      data[rnd] = -1;
    }
  }
  return 0;
}

/*
確率を出力する関数
*/
void printResult() {
  int sum = 0;
  int sum_capital = 0;

  for (char c = '0'; c <= '9'; c++) {
    printf("%c: %d times\n", c, ascii[c]);
    sum += ascii[c];
  }
  sum_capital += sum;
  printf("SUM = %d\n", sum);
  printf("-------------------------------------\n");

  sum = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    printf("%c: %d times\n", c, ascii[c]);
    sum += ascii[c];
  }
  sum_capital += sum;
  printf("SUM = %d\n", sum);
  printf("-------------------------------------\n");

  sum = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    printf("%c: %d times\n", c, ascii[c]);
    sum += ascii[c];
  }
  sum_capital += sum;
  printf("SUM = %d\n", sum);
  printf("-------------------------------------\n");

  sum = 0;
  printf("%c: %d times\n", '@', ascii['@']);
  printf("%c: %d times\n", '$', ascii['$']);
  sum = ascii['@'] + ascii['$'];
  sum_capital += sum;
  printf("SUM = %d\n", sum);
  printf("-------------------------------------\n");

  printf("SUM_CAPITAL = %d\n", sum_capital);
}

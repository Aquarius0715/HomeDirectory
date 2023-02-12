#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void swap(double *bpt, double *rpt);
void disp(double *bpt);
void genRand(double *bpt);

int main () {

//変数宣言
  double base[SIZE];
  double rev[SIZE];

// タネの初期化
  srand((unsigned) time(NULL));
// ポインタを用いて実数乱数を格納
  genRand(base);
// 順番に入れた要素を表示
  disp(base);
// base配列を逆から読み込み、rev配列に値を格納
  swap(base, rev);
// 逆順に格納した値を表示
  disp(rev);
  return 0;
}

// 配列の中身を入れ替える関数
void swap(double *bpt, double *rpt) {
  for (int i = 0; i < SIZE; i++) {
    *(rpt + i) = *((bpt + (SIZE - 1)) - i);
  }
}

// 配列の中身を表示させる関数
void disp(double *bpt) {
  for (int i = 0; i < SIZE; i++) {
    printf("%.1lf\n", *(bpt + i));
  }
  printf("\n");
}

void genRand(double *bpt) {
  for (int i = 0; i < SIZE; i++) {
    *(bpt + i) = (double) rand() / RAND_MAX;
  }
}

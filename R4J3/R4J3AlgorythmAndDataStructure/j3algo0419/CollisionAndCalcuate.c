#include <stdio.h>

/* 配列のサイズを定義 */
#define N 4

/* 関数プロトタイプ宣言 */
void sort(float *f);

int main() {
  /* 各座標を格納する配列を宣言 */
  float x[N];
  float y[N];

  /* コンソールから各図形の座標を入力 */
  printf("Input format: [R1 R2 L1 L2]\n");
  printf("Input P Positions: ");
  scanf("%f %f %f %f", &x[0], &y[0], &x[1], &y[1]);
  printf("Input Q Positions: ");
  scanf("%f %f %f %f", &x[2], &y[2], &x[3], &y[3]);

  /* 座標を降順でソート */
  sort(x);
  sort(y);

  /* 面積を計算 */
  float area = (x[1] - x[2]) * (y[1] - y[2]);

  /* 結果を出力 */
  printf("Area of collision is %f\n", area);
  
  return 0;
}

/* 降順にソートする関数 */
void sort(float *f) {
  int i, j, k, min, temp;
  for (i = 0; i < N; i++) {
    min = f[i];
    k = i;
    for (j = i + 1; j < N; j++) {
      if (f[j] > min) {
	min = f[j];
	k = j;
      }
    }
    temp = f[i];
    f[i] = f[k];
    f[k] = temp;
  }
}

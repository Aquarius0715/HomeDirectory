#include <stdio.h>

int isExistsPoint(float a[], float b[], float c[], float x[]) {

  //座標の宣言
  float a1[2] = {0, a[1] - b[1]};
  float b1[2] = {b[0] - a[0], 0};
  float c1[2] = {c[0] - a[0], 0};

  printf("ax: %f, ay: %f\n", a1[0], a1[1]);
  printf("bx: %f, by: %f\n", b1[0], b1[1]);
  printf("cx: %f, cy: %f\n", c1[0], c1[1]);

  //比例の式を計算
  float k = x[1] - a1[1] / x[0];
  float cross = -(a[1] / k);

  //printf("傾き: %f\n", k);
  //printf("X軸との交点の座標: %f\n", cross);

  if (cross <= c[0] && cross >= b[0]) {

    return 1;

  } else {

    return 0;
    
  }
  
}
  

int main () {

  float a[2] = {10.0, 10.0};
  float b[2] = {6.0, 0.0};
  float c[2] = {20.0, 20.0};
  float x[2] = {2.0, 3.0};

  if (isExistsPoint(a, b, c, x)) {

    printf("三角形の中に座標が存在します。\n");
    
  } else {

    printf("三角形の中に座標が存在しません。\n");
    
  }
  
  return 0;
  
}

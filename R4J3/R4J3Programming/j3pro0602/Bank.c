#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct {
  /** TEXTサイズ **/
  char name[1024];
  /** 口座番号は7桁 **/
  char number[7];
  /** unsigned longまで想定しているため20桁**/
  char balance[20];
} Account;

int main(void) {
  /** 変数の宣言 **/
  int i, j, c, upper, lower;
  
  /** 口座情報の配列を宣言 **/
  Account map[N];

  /** 口座情報を標準入力から取得 **/
  for (i = 0; i < N; i++) {
    /** 名前 **/
    printf("[%2d]Type name   : ", i + 1);
    scanf("%s", map[i].name);
    /** 口座番号 **/
    printf("[%2d]Type number : ", i + 1);
    scanf("%s", map[i].number);
    /** 残高 **/
    printf("[%2d]Type balance: ", i + 1);
    scanf("%s", map[i].balance);
  }

  /** 検索を掛ける範囲を標準入力から取得 **/
  /** 下限 **/
  printf("Type lower  : ");
  scanf("%d", &lower);
  /** 上限 **/
  printf("Type upper  :");
  scanf("%d", &upper);

  /** 残高が範囲内なら出力 **/
  for (i = 0, c = 1; i < N; i++) {
    unsigned long balance = atol(map[i].balance);
    if (balance >= lower && balance <= upper) {
      printf("================== %d =================\n", c);
      printf("name          : %s\n", map[i].name);
      printf("account number: %s\n", map[i].number);
      printf("balance       : %s\n", map[i].balance);
      printf("=======================================\n");
      c++;
    }
  }
  return 0;
}

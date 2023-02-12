#include <stdio.h>

#define MAXLEN 8

int main(void)
{
  char name[MAXLEN];

  printf("名前をローマ字で入力してください:");
  scanf("%s", name);

  printf("あなたの名前は%sです\n", name);

  return 0;
}

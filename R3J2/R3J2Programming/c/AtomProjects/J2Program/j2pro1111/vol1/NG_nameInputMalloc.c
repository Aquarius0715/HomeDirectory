#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int len;
  char *name;

  printf("名前の文字数を入力してください:");
  scanf("%d", &len);

  name = (char *)malloc(sizeof(char)*(len+1));

  printf("名前をローマ字で入力してください:");
  scanf("%s", name);

  printf("あなたの名前は%sです\n", name);

  return 0;
}

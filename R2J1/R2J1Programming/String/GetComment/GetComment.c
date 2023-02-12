#include <stdio.h>
#include <stdlib.h>

#define N 256

int main () {
    FILE *fp;
  char fname[] = "sample_text.txt";
  char str[N];

  fp = fopen(fname, "r");
  if (fp == NULL) {
    printf("ファイル名「%s」の参照に失敗しました。\n", fname);
    return -1;
  } else {
    printf("ファイル名「%s」の参照に成功しました。\n", fname);
  }

  while (fgets(str, N, fp) != NULL) {
    for (int i = 0; i < sizeof(str); i++) {
      if (str[i] == ' ') {
	continue;
      } else {
	if (str[i] == '/') {
	  printf("%s", str);
	}
	break;
      }
    }
  }
  fclose(fp);
  return 0;
}

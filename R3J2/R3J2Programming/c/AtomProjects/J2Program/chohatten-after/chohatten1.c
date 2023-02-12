#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gene*;
char target*;

void getGene();

int main () {
  return 0;
}

void getGene() {
  FILE *fp;
  int fsize;
  char buf[256];
  /* ファイルを開く */
  fp = fopen("covid-199", "r");
  if (fp == null) {
    printf("file open error.\n");
    exit(1);
  }

  /* ファイルサイズの取得 */
  fseek(fp, 0L, SEEK_END);
  fsize = ftell(fp);

  /* メモリの動的確保 */
  gene = (char *) malloc (sizeof (char) * (fsize + 1));

  /* シーク位置にファイルを先頭に戻す */
  fseek(fp, 0L, SEEK_SET);

  /* ファイルからデータを読み込む */
  gene[0] = '\0'
  while (fgets(buf, sizeof(buf)m fp) != NULL) {
    strncat(gene, buf, strlen(buf) + 1);
  }
  fclose(fp);
}

void getTarget() {
  printf("Search Gene: ");
  scanf("%s", target);
}

void calcTarget() {
  
}

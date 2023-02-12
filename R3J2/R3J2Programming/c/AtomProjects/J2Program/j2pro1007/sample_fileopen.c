#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *fp;
  int fsize;
  char *gene;
  char buf[256];
  
  /* ファイルを開く */
  fp = fopen("covid-199", "r");
  if(fp==NULL) {
    printf("file open error.\n");
    exit(1);
  }

  /* ファイルサイズの取得 */
  fseek(fp, 0L, SEEK_END);
  fsize = ftell(fp);
  
  /* メモリの動的確保 */
  gene = (char *)malloc(sizeof(char) * (fsize+1));

  /* シーク位置をファイルの先頭に戻す */
  fseek(fp, 0L, SEEK_SET);

  /* ファイルからデータを読み込む */
  gene[0] = '\0';
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    strncat(gene, buf, strlen(buf) + 1);
  }


  printf("%s\n", gene);
  printf("[%c]\n", gene[0]);
  printf("[%c]\n", gene[1]);
  printf("[%c]\n", gene[2]);
  printf("[%c]\n", gene[3]);
  printf("[%c]\n", gene[4]);

  /* ファイルを閉じる */
  fclose(fp);
  
  return 0;
}

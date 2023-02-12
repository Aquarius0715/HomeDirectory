#include <stdio.h>
#include <stdlib.h>

int insure_rows(char ***pt);
void set_names(char **pt, int rows);
void get_name(char **pt, int row);

int main() {
  char **names;
  int rows = insure_rows(&names);
  set_names(names, rows);
  get_name(names, rows);
  free(names);
  return 0;
}

int insure_rows(char ***pt) {
  int n;
  while (1) {
    printf("何人登録しますか -> ");
    scanf("%d", &n);
    if (n < 1) {
      printf("無効な値です\n");
      continue;
    }
    *pt = (char **)malloc(sizeof(char *) * n);
    break;
  }
  return n;
}

void set_names(char **pt, int rows) {
  int i;
  for (i = 0; i < rows; i++) {
    int n;
    char dummy;
    printf("%d人目の名前の文字数は -> ", i + 1);
    scanf("%d%c", &n, &dummy);
    pt[i] = (char *)malloc(sizeof(char) * (n + 1));
    printf("名前を入力してください -> ");
    fgets(pt[i], n + 1, stdin);
  }
  printf("入力が完了しました\n");
}

void get_name(char **pt, int row) {
  int n;
  printf("番号を入力してください -> ");
  scanf("%d", &n);
  if (n > row || n < 1) {
    printf("無効な値です。\n");
    return;
  }
  printf("%d番: %s\n", row, pt[row - 1]);
}

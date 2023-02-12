/** 各ヘッダーのインクルード  **/
#include <stdio.h>

/** 型定義 **/
typedef char* string;
typedef struct {
  int count;
  string str;
} Data;

/** 関数プロトタイプ宣言 **/
int equals(string s1, string s2);
int length(string s);
int contains(string s, Data *d, int cnt);
Data init(int count, string str);

int main(int argc, char *argv[]) {
  int i, idx, cnt;
  Data map[argc];
  
  if (argc == 1) {
    printf("usage: %s <strings...>\n", argv[0]);
    printf("please try again\n");
    return 0;
  }
  for (i = 1, cnt = 0; i < argc; i++) {
    if (i == 1 || (idx = contains(argv[i], map, cnt)) == -1) {
      map[cnt] = init(1, argv[i]);
      cnt++;
    } else {
      map[idx].count = map[idx].count + 1;
    }
  }
  for (i = 0; i < cnt; i++) {
    printf("%s %d\n", map[i].str, map[i].count);
  }
  return 0;
}


int equals(string s1, string s2) {
  int i = 0;
  if (length(s1) != length(s2)) {
    return 0;
  }
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}

int length(string s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

  
int contains(string s, Data *d, int cnt) {
  int i = 0;
  while (i < cnt) {
    if (equals(s, d[i].str) == 1) {
      return i;
    }
    i++;
  }
  return -1;
}

Data init(int count, string str) {
  Data d = {count, str};
  return d;
}

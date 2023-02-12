#include <stdio.h>

int len(char *str) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}

int contains(char *map, char element) {
  int i = 0;
  while (map[i] != '\0') {
    if (map[i] == element) {
      return 1;
    }
    i++;
  }
  return 0;
}

int main() {
  char string[] = "tokyo chiba saitama";
  char map[len(string) + 1];

  for (int i = 0; i < len(string); i++) {
    map[i] = '\0';
  }
  
  int i, k;
  for (i = 0, k = 0; string[i] != '\0'; i++) {
    if (string[i] == ' ') {
      continue;
    }
    if (!contains(map, string[i])) {
      printf("%c", string[i]);
      map[k] = string[i];
      k++;
    }
  }
  printf("\n");
  return 0;
}

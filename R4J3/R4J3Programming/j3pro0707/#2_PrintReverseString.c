#include <stdio.h>

int len(char *s) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

void reverseString(char *s, int length) {
  if (length < 0) {
    printf("\n");
    return;
  }
  printf("%c", s[length]);
  return reverseString(s, length - 1);
}

int main() {
  char s[256];
  scanf("%s", s);
  reverseString(s, len(s) - 1);
  return 0;
}

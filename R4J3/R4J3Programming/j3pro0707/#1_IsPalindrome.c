#include <stdio.h>

int len(char *str) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}

int isPalindrome(char *str, int first, int last) {
  if (first - last == 1 || first == last) {
    return 1;
  }
  if (str[first] == str[last]) {
    return isPalindrome(str, first + 1, last - 1);
  }
  return 0;
}

int main() {
  char s[256];
  scanf("%s", s);
  if (isPalindrome(s, 0, len(s) - 1)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}

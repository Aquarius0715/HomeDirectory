#include <stdio.h>

int length(char str*);

int main() {
  char target* = "tiktoktiktictiktik";
  char str* = "tiktik";
  int targetLength = length(target);
  int strLength = length(str);

  for (int i = 0; i < targetLength; i++) {
    for (int j = 0; j < strLength; j++) {
      if (target[i] == str[j]) {
	continue;
      }
    }
  }
  return 0;
}

int length(char str*) {
  int i = 0;
  while (str[0] != '\0') {
    i++;
  }
  return i;
}

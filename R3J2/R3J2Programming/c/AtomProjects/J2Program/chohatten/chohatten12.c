#include <stdio.h>

char convertBigCapital(char c);
void changeString(char string[]);

int main () {
  char string[] = "Do you like hotdog? I like hotdog because it is not dog.";
  changeString(string);
  printf("%s\n", string);
  return 0;
}

void changeString(char string[]) {
  for (int i = 1; string[i] != '\0'; i++) {
    if (string[i] == ' ') {
      string[i + 1] = convertBigCapital(string[i + 1]);
    }
  }
}

char convertBigCapital(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  } else {
    return c;
  }
}

#include <stdio.h>

char my_toupper(char ch);

int main () {
  char character;
  char result;
  printf("Type your character: ");
  scanf("%c", &character);
  result = my_toupper(character);
  printf("%c\n", result;
  return 0;
}

char my_toupper(char ch) {
  if (ch >= 'z' && ch <= 'a') {
    return ch;
  } else {
    return ch - ('a' - 'A');
  }
  return 'e';
}

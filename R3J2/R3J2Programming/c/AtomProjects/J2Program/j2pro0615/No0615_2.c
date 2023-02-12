#include <stdio.h>

int isSmollCapital(char c);

int main () {

  char character;

  for (int i = 0; !isSmollCapital(character) ; i++) {
    printf("type your number!!: ");
    scanf("%c", &character);
  }

printf("Your character is %c\n", character);


return 0;

}

int isSmollCapital(char c) {
  if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

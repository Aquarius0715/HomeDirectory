include <stdio.h>

char henkan(char c) {

  if (c >= 'A' && c <= 'Z') {

    return c + 32;
    
  } else if (c >= 'a' && c <= 'z') {

    return c - 32;
    
  } else {

    return null;
    
  }

  int main () {

    char c = 'a';

    printf("Type any Character!!\n");

    printf("Character: ");

    scanf("%d", &c);

    printf("Converted Character: %c\n", henkan(c));
    
  }

}

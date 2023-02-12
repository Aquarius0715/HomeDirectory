#include <stdio.h>

void encrypt(char plainText[], int key);
void init();

char data[26];

int main () {
  char plainText[] = "osyiaikuoguwmguoguwguyaikgiwioogu";
  int key = 0;

  init();

  printf("Type key: ");
  scanf("%d", &key);

  encrypt(plainText, key);

  printf("%s\n", plainText);

  return 0;
}

void encrypt(char plainText[], int key) {
  int i = 0;
  while (plainText[i] != '\0') {
    char c = plainText[i];
    if (c + key > 'z') {
      plainText[i] = data[c + key - 'z' - 1];
    } else {
      plainText[i] += key;
    }
    i++;
  }
}

void init() {
  char c = 'a';
  int i = 0;
  while (c <= 'z') {
    data[i] = c;
    c++;
    i++;
  }
}

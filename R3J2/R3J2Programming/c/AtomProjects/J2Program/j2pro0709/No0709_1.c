#include <stdio.h>

void decrypt(char ciphertext[]);

int main () {

  char ciphertext[] = "lpvtfobjlpvuboptijjob";

  decrypt(ciphertext);
  printf("%s\n", ciphertext);
  return 0;
}

void decrypt(char ciphertext[]) {
  int i = 0;
  while (ciphertext[i] != '\0') {
    if (ciphertext[i] == 'a') {
      ciphertext[i] = 'z';
    } else {
      ciphertext[i]--;
    }
    i++;
  }
}

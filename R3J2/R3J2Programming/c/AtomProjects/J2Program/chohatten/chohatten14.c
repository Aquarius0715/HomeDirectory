#include <stdio.h>

/*
(1)667050865286364666584674385846665846485846507860625860748666665846
(2)665846507860728648584878625838587074866666584680785046
(3)6858467258464858707884864886707066466686706678704886707066466686706678704858707884866858467258466658467486666686
*/

void decrypt();

char cryptGraph[] = "667050865286364666584674385846665846485846507860625860748666665846";
char decryptGraph[128];

int main () {
  decrypt(cryptGraph);
  printf("%s\n", decryptGraph);
  return 0;
}

void decrypt() {
  int i = 0;
  int index = 0;
  while (cryptGraph[i] != '\0') {
    char c = (cryptGraph[i] - '0') * 10 + cryptGraph[i + 1] - '0';
    c = c%26+'a';
    printf("%c\n",c);
    decryptGraph[index] = c;
    index++;
    i += 2;
  }
}

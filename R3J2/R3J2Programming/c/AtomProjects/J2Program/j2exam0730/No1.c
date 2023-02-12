#include <stdio.h>
#include <stdlib.h>

#define NUM 30

void dispString_Odd(char str[]);
int randomMinToMax(int min, int max);
void setCharacter(char string[]);

int main(void)
{

  for (int i = 0; i < 100; i++) {
    int rnd = randomMinToMax(0, 10);
    printf("%d times: %d\n", i, rnd);
  }

  return 0;
}

void No1() {
  char box[NUM+1];

  srand(730);
  setCharacter(box);
  printf("%s\n", box);
  dispString_Odd(box);
}

int randomMinToMax(int min, int max) {
  return rand() % (max - min) + min + 1;
}

void setCharacter(char string[])
{
  int i = 0;
  while (i < NUM) {
    string[i] = randomMinToMax('a', 'z');
    i++;
  }
}


void dispString_Odd(char str[])
{
  int i = 0;
  while (str[i] != '\0') {
    printf("%c ", str[i]);
    i += 2;
  }
  printf("\n");
}

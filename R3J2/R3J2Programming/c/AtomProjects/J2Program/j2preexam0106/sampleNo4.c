#include <stdio.h>

void compress(char plain[]);
void expand(char code[]);

int main(void)
{
  char plain[] = "aaaabbbcccccccaa";
  char code[] = "a4b3c7a2";
  //char plain2[] = "kkkedvvvvQQQQ";
  //char code2[] = "k3e1d1v4Q4";

  compress(plain);

  expand(code);

  return 0;
}

void compress(char plain[])
{
  printf("---- compress() ----\n");
  printf("plain = %s\n", plain);

  /* write your code here. */
  
  printf("\n");
}

void expand(char code[])
{
  printf("---- expand() ----\n");
  printf("code = %s\n", code);

  /* write your code here. */

  printf("\n");
}

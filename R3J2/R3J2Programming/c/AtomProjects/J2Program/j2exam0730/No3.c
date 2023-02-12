#include <stdio.h>

void ascii();

int main(void)
{
  //char str1[] = "979899";
  char str1[] = "7510511597114971221173275111117115101110";

  int i = 0;
  while (str1[i] != '\0') {
    int n1 = str1[i] - '0';
    int n2 = str1[i + 1] - '0';
    int n3 = str1[i + 2] - '0';

    char c = 0;
    if (n1 > 6) {
      c = (n1 * 10) + n2;
      i += 2;
      printf("%c", c);
      continue;
    }
    if (n1 == 1) {
      c = (n1 * 100) + (n2 * 10) + n3;
      i += 3;
      printf("%c", c);
      continue;
    }
    if (n1 == 3) {
      printf(" ");
      i += 2;
      continue;
    }
  }
  printf("\n");
  return 0;
}

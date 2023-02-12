#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomMinToMax(int min, int max);
void generatePassword(int n, char *pt);

int main() {
  int length;

  srand((unsigned) time (NULL));


  while (1) {
    printf("type length -> ");
    scanf("%d", &length);
    if (length >= 8 && length <= 32) {
      break;
    } else {
      printf("number error\n");
      continue;
    }
  }
  char *password = (char *)malloc(sizeof(char) * (length + 1));

  generatePassword(length, password);

  printf("%s\n", password);
  printf("length=%d\n", length);

  free(password);

  return 0;
}

void generatePassword(int n, char *pt) {
 for (int i = 0; i < n; i++) {
  pt[i] = randomMinToMax('a', 'z');
 }
}

int randomMinToMax(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

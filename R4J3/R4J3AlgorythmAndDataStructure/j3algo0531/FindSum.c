#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, i, j;
  int s[argc - 2], f[argc - 2];
  int map[2000][2000];
  
  if (argc < 4) {
    printf("usage: %s <X> <numbers...>\n", argv[0]);
    printf("please try again\n");
    return 0;
  }
  for (i = 0; i < 2000; i++) {

  }
  
  x = atoi(argv[1]);
  for (i = 0; i < argc - 2; i++) {
    s[i] = atoi(argv[i + 2]);
  }

  for (i = 0; i < argc - 2; i++) {
    for (j = 0; j < argc - 2; j++) {
      if (i == j) {
	continue;
      }
      if (s[i] + s[j] == x) {
	printf("%d, %d\n", s[i], s[j]);
      }
    }
  }
  return 0;
}

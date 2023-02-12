#include <stdio.h>

int main() {
  int n;
  printf("Input Rows: ");
  scanf("%d", &n);
  
  int map[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      map[i][j] = 0;
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == 1) {
	map[i][j] = 1;
      } else if (j == i) {
	map[i][j] = 1;
	break;
      } else {
	map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
<<<<<<< HEAD
      printf("%d ", map[i][j]);
=======
      printf("%5d ", map[i][j]);
>>>>>>> 3ec92b612eb178104187483a706d983467fdefb2
    }
    printf("\n");
  }
  return 0;
}

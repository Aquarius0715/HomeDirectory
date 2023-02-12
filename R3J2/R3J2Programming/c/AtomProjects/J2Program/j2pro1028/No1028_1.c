#include <stdio.h>

#define ROW 3
#define COLOMN 4

void set_matrix(int matrix[ROW][COLOMN]);
void disp_matrix(int matrix[ROW][COLOMN]);

int main () {

  int matrix[ROW][COLOMN];

  set_matrix(matrix);
  disp_matrix(matrix);

  return 0;
}

void set_matrix(int matrix[ROW][COLOMN]) {
  int i, j;
  int c = 0;

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COLOMN; j++) {
      matrix[i][j] = c;
      c++;
    }
  }
}

void disp_matrix(int matrix[ROW][COLOMN]) {
  int i, j;

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COLOMN; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

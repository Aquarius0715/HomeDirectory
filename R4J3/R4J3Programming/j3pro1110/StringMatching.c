#include <stdio.h>

#define GAP_SCORE -2

typedef struct Cell {
  int MatchScore;
  int LeftScore;
  int DiagonalScore;
  int UpperScore;
} Cell;

int length(char* string);
void createMatchingTable(Cell **table, int columnSize, int rowSize);
int getMaxScore(Cell cell);

char str1[] = {"ATTGC"};
char str2[] = {"ATGC"};

int main(void) {
  Cell table[length(str1)][length(str2)];
  return 0;
}

int length(char* string) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}

int getMaxScore(Cell cell) {
  int leftScore = cell.LeftScore;
  int diagonalScore = cell.DiagonalScore;
  int upperScore = cell.UpperScore;

  if (leftScore > diagonalScore && leftScore > upperScore) {
    return leftScore;
  } else if (diagonalScore > leftScore && diagonalScore > upperScore) {
    return diagonalScore;
  } else {
    return upperScore;
  }
}

void createMatchingTable(Cell **table, int columnSize, int rowSize) {
  int i, j;
  for (i = 0; i < columsSize; i++) {
    for (j = 0; j < rowSize; i++) {
      Cell cell = {0, 0, 0, 0};
      int matchScore;
      if (str1[i] == str2[j]) {
	cell.MatchScore = 2;
	matchScore = 2;
      } else {
	cell.MatchScore = -1;
	matchScore = -1;
      }
      if (j == 0) {
	cell.LeftScore = GAP_SCORE * (i + 1);
      } else {
	cell.LeftScore = getMaxScore(table[i][j - 1]) + GAP_SCORE;
      }
      
    }
  }
}

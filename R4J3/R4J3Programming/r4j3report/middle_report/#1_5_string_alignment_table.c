#include <stdio.h>

#define MATCH 2
#define MISMATCH -1
#define GAP -2

typedef struct {
  int matchScore;
  int leftScore;
  int diagonalScore;
  int upperScore;
  int score;
} Cell;

int len(char *str);
Cell init(int matchScore, int leftScore, int diagonalScore, int upperScore, int score);
int getScore(int leftScore, int diagonalScore, int upperScore);

int main(void) {
  char string1[256];
  char string2[256];
  
  scanf("%s", string1);
  scanf("%s", string2);

  Cell table[len(string1) + 1][len(string2) + 1];

  printf("format: [MatchScore, LeftScore, DiagonalScore, UpperScore, Score]\n");
  for (int i = 0; i < len(string2) + 1; i++) {
    for (int j = 0; j < len(string1) + 1; j++) {
      Cell cell;
      if (i == 0 && j == 0) {
	cell = init(0, 0, 0, 0, 0);
      } else if (i == 0 && j != 0) {
	cell = init(0, 0, 0, 0, GAP * j);
      } else if (i != 0 && j == 0) {
	cell = init(0, 0, 0, 0, GAP * i);
      } else {
	int matchScore;
	int leftScore;
	int diagonalScore;
	int upperScore;
	int score;
	if (string2[i - 1] == string1[j - 1]) {
	  matchScore = MATCH;
	} else {
	  matchScore = MISMATCH;
	}
	leftScore = table[i][j - 1].score + GAP;
	diagonalScore = table[i - 1][j - 1].score + matchScore;
	upperScore = table[i - 1][j].score + GAP;
	score = getScore(leftScore, diagonalScore, upperScore);
	cell = init(matchScore, leftScore, diagonalScore, upperScore, score);
      }
      table[i][j] = cell;
      printf("[%3d %3d %3d %3d %3d]", table[i][j].matchScore, table[i][j].leftScore, table[i][j].diagonalScore, table[i][j].upperScore, table[i][j].score);
    }
    printf("\n");
  }
    
  return 0;
}

int len(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

Cell init(int matchScore, int leftScore, int diagonalScore, int upperScore, int score) {
  Cell cell = {matchScore, leftScore, diagonalScore, upperScore, score};
  return cell;
}

int getScore(int leftScore, int diagonalScore, int upperScore) {
  int max = leftScore;
  if (max < diagonalScore) {
    max = diagonalScore;
  }
  if (max < upperScore) {
    max = upperScore;
  }
  return max;
}

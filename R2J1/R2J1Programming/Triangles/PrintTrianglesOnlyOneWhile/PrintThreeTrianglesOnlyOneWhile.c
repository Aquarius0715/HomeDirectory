#include <stdio.h>
#include <stdbool.h>

int main() {

  int blockCount = 0;
  int lineCount = 0;
  int stoneCount = 0;

  while(true) {
    if (blockCount == 3) {
      break;
    } else {
      if (lineCount > 5) {
	lineCount = 0;
	blockCount++;
      } else {
	if (lineCount <= stoneCount) {
	  printf("\n");
	  lineCount++;
	  stoneCount = 0; 
	} else {
	  printf("*");
	  stoneCount++;
	}
      }
    }
  }
  return 0;
}

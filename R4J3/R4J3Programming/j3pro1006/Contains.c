#include <stdio.h>

int main(void) {
  char string[] = "tiktoktiktik";
  char word[] = "tiktik";
  int i, j;
  int equalFlag, equalCount;\
  int compareCount;

  i = 0;
  equalCount = 0;
  compareCount = 0;
  while (string[i] != '\0') {
    j = 0;
    equalFlag = 1;
    while (word[j] != '\0') {
      compareCount++;
      printf("[%d:%d]%c と %cを比較: ",i ,j ,string[i + j], word[j]);
      if (string[i + j] != word[j]) {
	printf("NON EQUAL\n");
	equalFlag = 0;
	break;
      }
      printf("EQUAL\n");
      j++;
    }
    if (equalFlag == 1) {
      printf("MATCH WORD\n");
      equalCount++;
    }
    i++;
  }
  printf("\n");
  printf("CompareCount: %d\n", compareCount);
  return 0;
}

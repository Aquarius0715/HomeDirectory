#include <stdio.h>
#include <stdlib.h>

typedef struct num {
  int Data;
  struct num *Left, *Right;
} Number;


Number *FirstNumber = NULL;


int main(void) {
  int i;
  int Sequence[12] = {13, 8, 10, 21, 6, 12, 7, 19, 45, 51, 33, 6};
  Number *NewNumber, *TargetNumber;

  
  for (i = 0; i < 12; i++) {
    NewNumber = (Number *) malloc(sizeof(Number));
    NewNumber -> Data = Sequence[i];
    NewNumber -> Left = NULL;
    NewNumber -> Right = NULL;
    if (FirstNumber == NULL) {
      FirstNumber = NewNumber;
      printf("「%d」が最初の値として格納されました。\n", Sequence[i]);
      continue;
    }
    TargetNumber = FirstNumber;
    while (1) {
      if (TargetNumber -> Data > Sequence[i]) {
	if (TargetNumber -> Left == NULL) {
	  TargetNumber -> Left = NewNumber;
	  printf("「%d」は「%d」の左に格納されました。\n", Sequence[i], TargetNumber -> Data);
	  break;
	} else {
	  TargetNumber = TargetNumber -> Left;
	}
      }
      if (TargetNumber -> Data < Sequence[i]) {
	if (TargetNumber -> Right == NULL) {
	  TargetNumber -> Right = NewNumber;
	  printf("「%d」は「%d」の右に格納されました。\n", Sequence[i], TargetNumber -> Data);
	  break;
	} else {
	  TargetNumber = TargetNumber -> Right;
	}
      }
      if (TargetNumber -> Data == Sequence[i]) {
	printf("「%d」は既に存在しているので格納されませんでした。\n", Sequence[i]);
	free(NewNumber);
	break;
      }
    }
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct num {
  int Data;
  int Count;
  struct num *NextData;
} Number;

Number *L[10] = {NULL};

void AddData();
void DisplayData();
void DisplayEach(int Index);

int main(void) {
  char KeyBoardInput, Options;
  while (Options != 'Q') {
    printf("A: Add Data, D: Display Data, Q: Quit\n");
    printf("Type desired options(A, D, Q)\n");
    scanf("%s", &KeyBoardInput);
    Options = toupper(KeyBoardInput);
    switch (Options) {
    case 'A':
      AddData();
      break;
    case 'D':
      DisplayData();
      break;
    default:
      printf("Invalid Option.\n");
      break;
    }
  }
  return 0;
}

void AddData() {
  Number *NewNumber, *CurrentNumber;
  int NewData, Index;
  printf("Enter the number:\n");
  scanf("%d", &NewData);
  Index = NewData % 10;
  NewNumber = (Number*) malloc(sizeof(Number));
  if (L[Index] == NULL) {
    NewNumber -> Data = NewData;
    NewNumber -> Count = 1;
    NewNumber -> NextData = NULL;
    L[Index] = NewNumber;
    printf("%d is added.\n", NewData);
    return;
  }
  CurrentNumber = L[Index];
  while (CurrentNumber -> NextData != NULL) {
    if (CurrentNumber -> Data == NewData) {
      CurrentNumber -> Count += 1;
      printf("%d count up.\n", NewData);
      return;
    }
    CurrentNumber = CurrentNumber -> NextData;
  }
  NewNumber -> Data = NewData;
  NewNumber -> Count = 1;
  NewNumber -> NextData = NULL;
  CurrentNumber -> NextData = NewNumber;
  printf("%d is addred.\n", NewData);
}

void DisplayData() {
  int Index;
  for (Index = 0; Index < 10; Index++) {
    if (L[Index] == NULL) {
      printf("L[%d] == NULL\n", Index);
    } else {
      DisplayEach(Index);
    }
  }
}

void DisplayEach(int Index) {
  Number *DisplayIt;
  DisplayIt = L[Index];
  printf("L[%d] == ", Index);
  while (DisplayIt -> NextData != NULL) {
    printf("N = %d, C = %d| ", DisplayIt -> Data, DisplayIt -> Count);
    DisplayIt = DisplayIt -> NextData;
  }
  printf("\n");
}

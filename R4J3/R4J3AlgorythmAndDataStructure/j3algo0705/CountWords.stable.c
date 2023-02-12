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
  if (L[Index] == NULL) {
    NewNumber = (Number*) malloc(sizeof(Number));
    L[Index] = NewNumber;
    NewNumber -> Data = NewData;
    NewNumber -> Count = 1;
    NewNumber -> NextData = NULL;
    printf("%d is added.\n", NewData);
    return;
  }
  CurrentNumber = L[Index];
  /*
  while (CurrentNumber -> NextData != NULL) {
    if (CurrentNumber -> Data == NewData) {
      CurrentNumber -> Count += 1;
      printf("%d count up.\n", NewData);
      return;
    }
    CurrentNumber = CurrentNumber -> NextData;
  }
  */
  while (1) {
    if (CurrentNumber -> Data == NewData) {
      CurrentNumber -> Count = CurrentNumber -> Count + 1;
      printf("Number already exists. Count up.\n");
      return;
    } else if (CurrentNumber -> NextData != NULL) {
      CurrentNumber = CurrentNumber -> NextData;
    } else {
      break;
    }
  }
  NewNumber = (Number*) malloc(sizeof(Number));
  CurrentNumber -> NextData = NewNumber;
  NewNumber -> Data = NewData;
  NewNumber -> Count = 1;
  NewNumber -> NextData = NULL;
  printf("%d is addred.\n", NewData);
}

void DisplayData() {
  int Index;
  for (Index = 0; Index < 10; Index++) {
    if (L[Index] == NULL) {
      continue;
    } else {
      DisplayEach(Index);
    }
  }
}

void DisplayEach(int Index) {
  Number *DisplayIt;
  DisplayIt = L[Index];
  while (1) {
    printf("%3d: %2d回\n", DisplayIt -> Data, DisplayIt -> Count);
    if (DisplayIt -> NextData != NULL) {
      DisplayIt = DisplayIt -> NextData;
    } else {
      break;
    }
  }
}

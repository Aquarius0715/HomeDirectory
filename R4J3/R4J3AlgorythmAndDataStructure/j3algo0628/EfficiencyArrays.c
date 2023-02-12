#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct num {
  int Data;
  struct num * NextData;
} Number;

Number *L[10] = {NULL};

void AddData();
void DisplayData();
void DisplayEach(int Index);

int main(void) {
  char KeyBoardInput, Options;
  while (1) {
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
    case 'Q':
      return 0;
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
    NewNumber -> NextData = NULL;
    printf("%d is added.\n", NewData);
    return;
  }
  CurrentNumber = L[Index];
  if (CurrentNumber -> Data == NewData) {
    printf("Number already exists. No Entry made.\n");
    return;
  }
  while (1) {
    if (CurrentNumber -> Data == NewData) {
      printf("Number already exists. No Entry made.\n");
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
  NewNumber -> NextData = NULL;
  printf("%d is added.\n", NewData);
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
  while (1) {
    printf("%d| ", DisplayIt -> Data);
    if (DisplayIt -> NextData != NULL) {
      DisplayIt = DisplayIt -> NextData;
    } else {
      printf("\n");
      break;
    }
  }
}

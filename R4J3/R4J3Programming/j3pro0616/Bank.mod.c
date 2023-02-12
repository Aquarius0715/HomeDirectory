#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Account {
  char name[25];
  char number[8];
  char balance[100];
  struct Account *NextAccount;
} BankAccount;

BankAccount *FirstAccount = NULL;
BankAccount *LastAccount = NULL;

void AddAccount();
void DisplayAccount();

int main(void) {
  char KeyBoardInput, Options;
  while (1) {
    printf("A: AddMembers, D: DisplayMembers, Q: Quit\n");
    printf("Type desired options(A, D, Q):");
    scanf("%s", &KeyBoardInput);
    Options = toupper(KeyBoardInput);
    switch (Options) {
    case 'A':
      AddAccount();
      break;
    case 'D':
      DisplayAccount();
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

void AddAccount() {
  BankAccount *NewAccount;
  NewAccount = (BankAccount*) malloc(sizeof(BankAccount));
  printf("Enter Details of New Account:\n");
  printf("AccountName(Without Space)\n");
  scanf("%s", NewAccount -> name);
  printf("AccountNumber(7 Digits)\n");
  scanf("%s", NewAccount -> number);
  printf("AccountBalance\n");
  scanf("%s", NewAccount -> balance);
  NewAccount -> NextAccount = NULL;
  if (FirstAccount == NULL && LastAccount == NULL) {
    FirstAccount = NewAccount;
    LastAccount = NewAccount;
  } else {
    LastAccount -> NextAccount = NewAccount;
    LastAccount = NewAccount;
  }
}

void DisplayAccount() {
  if (FirstAccount == NULL && LastAccount == NULL) {
    printf("Not Exists Account in Accounts List\n");
  } else {
    printf("=============== FirstAccount ===============\n");
    printf("AccountName   : %s\n", FirstAccount -> name);
    printf("AccountNumber : %s\n", FirstAccount -> number);
    printf("AccountBalance: %s\n", FirstAccount -> balance);
    printf("=============== FirstAccount ===============\n\n");
    printf("=============== LastAccount ===============\n");
    printf("AccountName   : %s\n", LastAccount -> name);
    printf("AccountNumber : %s\n", LastAccount -> number);
    printf("AccountBalance: %s\n", LastAccount -> balance);
    printf("=============== LarstAccount ===============\n\n");
  }
}

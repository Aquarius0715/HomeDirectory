A#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Club {
  char FirstName[25];
  char LastName[25];
  char Department[25];
  int SchoolYear;
  int CommutingTime;
  int Fare;
  struct Club *NextMember;
} ClubMembers;

ClubMembers *FirstMember = NULL;

void AddMembers();
void DisplayMembers();

int main(void) {
  char KeyBoardInput,Options;
  while(1) {
    printf("A: Add Members, D:Display Members Q: Quit\n");
    printf("Type desired options(A,D, Q):");
    scanf("%s",&KeyBoardInput);
    Options = toupper(KeyBoardInput);
    switch (Options) {
      case 'A':
	AddMembers();
        break;
      case 'D':
        DisplayMembers();
        break;
      case 'Q':
        return 0;
      default:
        printf("Invalid Option.\n");
        break;
    }
  }
}

void AddMembers() {
  ClubMembers *NewMember;
  NewMember = (ClubMembers*) malloc(sizeof(ClubMembers));
  printf("Enter Details of New Member:\n");
  printf("First Name\n");
  scanf("%s",NewMember -> FirstName);
  printf("Last Name\n");
  scanf("%s",NewMember -> LastName);
  printf("Department(for eg. Information, Mechanical, Civil, Elecrical, Control etc)\n");
  scanf("%s",NewMember -> Department);
  printf("School Year (1~5)\n");
  scanf("%d",&NewMember -> SchoolYear);
  printf("Commuting Time(in minutes)\n");
  scanf("%d",&NewMember -> CommutingTime);
  printf("Transportation Fare(in JPY)\n");
  scanf("%d",&NewMember -> Fare);
  NewMember -> NextMember = NULL;
  if (FirstMember == NULL) {
    FirstMember = NewMember;
  } else {
    ClubMembers *LastMember;
    LastMember = FirstMember;
    while (LastMember -> NextMember != NULL) {
      LastMember = LastMember -> NextMember;
    }
    LastMember -> NextMember = NewMember;
  }
}

void DisplayMembers() {
  ClubMembers *DisplayIt;
  if (FirstMember == NULL) {
    printf("There is no member data.\n");
    return;
  }
  DisplayIt = FirstMember;
  int i = 1;
  while (1) {
    printf("=============== Member[%d] ===============\n", i);
    printf("FirstName     : %s\n", DisplayIt -> FirstName);
    printf("LastName      : %s\n", DisplayIt -> LastName);
    printf("Department    : %s\n", DisplayIt -> Department);
    printf("SchoolYear    : %d\n", DisplayIt -> SchoolYear);
    printf("CommutingTime : %d\n", DisplayIt -> CommutingTime);
    printf("Transportation: %d\n", DisplayIt -> Fare);
    printf("=============== Member[%d] ===============\n\n", i);
    if (DisplayIt -> NextMember != NULL) {
      DisplayIt = DisplayIt->NextMember;
    } else {
      break;
    }
    i++;
  }
}

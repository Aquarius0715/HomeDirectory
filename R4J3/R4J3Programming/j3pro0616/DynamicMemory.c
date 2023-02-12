#include <stdio.h>
#include <ctype.h>

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
ClubMembers *LastMember = NULL;

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
    if (FirstMember == NULL && LastMember == NULL) {
        FirstMember = NewMember;
        LastMember = NewMember;
    } else {
        LastMember -> NextMember = NewMember;
        LastMember = NewMember;
    }
}

void DisplayMembers() {
    if (FirstMember == NULL && LastMember == NULL) {
        printf("Not exists Member in Members.\n");
    } else {
        printf("=============== FirstMember ===============\n");
        printf("FirstName     : %s\n", FirstMember -> FirstName);
        printf("LastName      : %s\n", FirstMember -> LastName);
        printf("Department    : %s\n", FirstMember -> Department);
        printf("SchoolYear    : %d\n", FirstMember -> SchoolYear);
        printf("CommutingTime : %d\n", FirstMember -> CommutingTime);
        printf("Transportation: %d\n", FirstMember -> Transportation);
        printf("=============== FirstMember ===============\n");
        printf("=============== Last Member ===============\n");
        printf("FirstName     : %s\n", LastMember -> FirstName);
        printf("LastName      : %s\n", LastMember -> LastName);
        printf("Department    : %s\n", LastMember -> Department);
        printf("SchoolYear    : %d\n", LastMember -> SchoolYear);
        printf("CommutingTime : %d\n", LastMember -> CommutingTime);
        printf("Transportation: %d\n", LastMembe -> Transportation);
        printf("=============== Last Member ===============\n");
    }
}

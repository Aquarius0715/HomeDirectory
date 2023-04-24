#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

typedef struct data
{
  char Data;
  struct data *Down;
  struct data *Right;
}Data;

void AddWord();
void SearchAndInsert(Data* Node);
void DisplayNumbers(Data* Node);
void Travel(Data* Node,int n);
Data *NewData, *CurrentData, *Root=NULL;
char NewWord[100];
int pos;

int main()
{

 char KeyBoardInput,Options;
while(1) 
  {
  printf("A: Add Word, D:Display, Q: Quit\n");
  printf("Type desired options(A,D,Q):");
  scanf("%s",&KeyBoardInput);
  Options=toupper(KeyBoardInput);
  switch (Options)
   {
    case 'A':
    AddWord();
    break;
    case 'D':
    printf("Inserted Numbers are as follows\n");
    DisplayNumbers(Root);
    printf("\n");
    break;
    case 'Q':
    return 0;
    default:
    printf("Invalid Option.\n");
    break;
    }
  }
}

void AddWord()
{
  printf("単語を入力してください:\n"); 
  scanf("%s",NewWord);  
  if (Root==NULL)  
   {
     int i = 0;
     NewData=(Data*)malloc(sizeof(Data)); 
     NewData->Data=NewWord[i];   
     NewData->Right=NULL;
     NewData->Down=NULL;
     Root=NewData;
     CurrentData = NewData;
     
     for(i=1;NewWord[i]!='\0'&&pos<MAX;i++){
       NewData=(Data*)malloc(sizeof(Data)); 
       NewData->Data=NewWord[i];   
       NewData->Right=NULL;
       NewData->Down=NULL;
       CurrentData->Down=NewData;
       CurrentData=NewData;
     }
   }
     else
     {
       pos=0;
       SearchAndInsert(Root);
     }
}

void SearchAndInsert(Data *Node)
{
   if((NewWord[pos] != Node->Data)&& (Node->Right!=NULL)) 
     {
       SearchAndInsert(Node->Right);
     }
   else if((NewWord[pos] != Node->Data) && (Node->Right==NULL))
     {
       NewData=(Data*)malloc(sizeof(Data));
       Node->Right=NewData;
       NewData->Data=NewWord[pos];
       NewData->Right=NULL;
       CurrentData = NewData;
       
       for(pos++;NewWord[pos]!='\0'&&pos<MAX;pos++){
	 NewData=(Data*)malloc(sizeof(Data)); 
	 NewData->Data=NewWord[pos];   
	 NewData->Right=NULL;
	 NewData->Down=NULL;
	 CurrentData->Down=NewData;
	 CurrentData=NewData;
       }
     }
   else if((NewWord[pos]!=Node->Data)&&(Node->Down==NULL)){
      NewData=(Data*)malloc(sizeof(Data));
       Node->Down=NewData;
       NewData->Data=NewWord[pos];
       NewData->Right=NULL;
       CurrentData = NewData;
       
       for(;NewWord[pos]!='\0'&&pos<MAX;pos++){
	 NewData=(Data*)malloc(sizeof(Data)); 
	 NewData->Data=NewWord[pos];   
	 NewData->Right=NULL;
	 NewData->Down=NULL;
	 CurrentData->Down=NewData;
	 CurrentData=NewData;
       }
   }
    else{
      if((NewWord[pos]!='\0')&&(Node->Down!=NULL)){
      pos++;
      SearchAndInsert(Node->Down);
      }
      else{
	printf("all match");
	return;
      }
     }
}

void  DisplayNumbers(Data *Node)
{
  if (Root==NULL)
   {
    printf("No data exists\n");
    return;
   }
   else
   {
     Travel(Root,0);
   }
}

void Travel(Data *Node,int n){
  printf("%c",Node->Data);
  if(Node->Down!=NULL){
    Travel(Node->Down,n+1);
  }
  else{
    printf("\n");
  }

  if(Node->Right!=NULL){
    for(int i=0;i<n-1;i++){
    printf(" ");
    }
    printf("~");
    Travel(Node->Right,n);
  }
}




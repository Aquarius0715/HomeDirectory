#include <stdio.h>

void dispString(char str[]);
void dispWord(char str[]);
void dispWordCount(char str[]);
void dispWordMax(char str[]);

int main(void)
{
  char str[] = "apple,grape,pineapple,strawberry,lemon,orange,hogehogehogehoge";

  printf("(1)\n");
  dispString(str);


  printf("(2)\n");
  dispWord(str);


  printf("(3)\n");
  dispWordCount(str);


  printf("(4)\n");
  dispWordMax(str);


  return 0;
}


/*******
 * (1)
 *******/
void dispString(char str[])
{
  printf("%s\n\n", str);
}


/*******
 * (2)
 *******/
void dispWord(char str[])
{
  int i = 0;
  while (str[i] != '\0') {
      if (str[i] == ',') {
        printf("\n");
        i++;
        continue;
      }
      printf("%c", str[i]);
      i++;
  }
  printf("\n\n");
}


/*******
 * (3)
 *******/
void dispWordCount(char str[])
{
  int i = 0;
  int count = 0;
  while (str[i] != '\0') {
    if (str[i] == ',') {
      printf("%d ", count);
      count = 0;
      i++;
      continue;
    }
    count++;
    i++;
  }
  printf("%d\n\n", count);
}


/*******
 * (4)
 *******/
 #define WORDS 100
 #define LENGTH 100
void dispWordMax(char str[])
{
  char words[WORDS][LENGTH];
  int i = 0;
  int wordsCount = 0;
  int lengthCount = 0;

  while (str[i] != '\0') {
    if (str[i] == ',') {
      i++;
      wordsCount++;
      lengthCount = 0;
      continue;
    }
    words[wordsCount][lengthCount] = str[i];
    i++;
    lengthCount++;
  }

  int maxLength = 0;
  int maxWord = 0;
  wordsCount = 0;

  while (words[wordsCount][0] != '\0') {
    int length = 0;
    while (words[wordsCount][length] != '\0') {
      length++;
    }
    if (length > maxLength) {
      maxLength = length;
      maxWord = wordsCount;
    }
    wordsCount++;
  }

  printf("%s\n\n", words[maxWord]);
}

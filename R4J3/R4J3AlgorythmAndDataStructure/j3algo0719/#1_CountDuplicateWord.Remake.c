#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct String {
  char str[256];
  int hash;
  int count;
  struct String *next;
} String;


void add();
void display();
void displayEach();
int equals(char *s1, char *s2);
char* copy(char *original, char *copy);
int length(char *s);
int getHash(char *s);


String *vec[10] = {NULL};


int main(void) {
  char KeyBoardInput, Options;
  while (1) {
    printf("A: Add Data, D: DisplayData, Q: Quit\n");
    printf("Type desire options(A, D, Q):");
    scanf("%s", &KeyBoardInput);
    Options = toupper(KeyBoardInput);
    switch (Options) {
    case 'A':
      add();
      break;
    case 'D':
      display();
      break;
    case 'Q':
      return 0;
    default:
      printf("Invalid Option\n");
      break;
    }
  }
}

void add() {
  String *current, *new;
  char *s;
  int hash, index;
  printf("Type the word\n");
  scanf("%s", s);
  hash = getHash(s);
  index = hash % 10;
  new = (String *) malloc(sizeof(String));
  new -> hash = hash;
  new -> count = 1;
  new -> next = NULL;
  copy(s, new -> str);
  if (vec[index] == NULL) {
    vec[index] = new;
  } else {
    current = vec[index];
    while (1) {
      if (current -> hash == hash) {
	if (equals(current -> str, s) == 1) {
	  current -> count += 1;
	  printf("Count up successfully.\n");
	  free(new);
	  return;
	}
      } else if (current -> next != NULL) {
	current = current -> next;
      } else {
	break;
      }
    }
    current -> next = new;
  }
  printf("Add string successfully.\n");
}

void display() {
  int index;
  for (index = 0; index < 10; index++) {
    if (vec[index] == NULL) {
      continue;
    } else {
      displayEach(index);
    }
  }
}

void displayEach(int index) {
  String *displayIt;
  displayIt = vec[index];
  while (1) {
    printf("%s: %d times\n", displayIt -> str, displayIt -> count);
    if (displayIt -> next != NULL) {
      displayIt = displayIt -> next;
    } else {
      break;
    }
  }
}

int equals(char *s1, char *s2) {
  int i;
  for (i = 0; s1[i] == s2[i]; i++) {
    if (s1[i] == '\0') {
      return 1;
    }
  }
  return 0;
}

char* copy(char *original, char *copy) {
  int i;
  for (i = 0; original[i] != '\0'; i++) {
    copy[i] = original[i];
  }
  copy[i + 1] = '\0';
  return copy;
}

int length(char *s) {
  int i;
  for (i = 0; s[i] != '\0'; i++);
  return i;
}

int getHash(char *s) {
  int hash = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    hash += (int) s[i];
  }
  return hash;
}

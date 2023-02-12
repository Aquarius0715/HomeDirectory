#include <stdio.h>
#include <stdlib.h>

typedef struct character {
  char data;
  struct character *nextAddress;
  int addressCount;
} Character;

Character *rootCharacter = NULL;

Character* searchEndCharacter(Character *c, char ch);
void add(Character *c);

int main(void) {
  char keyBoardInput[256];
  while (1) {
    printf("Type Your Key: ");
    scanf("%s", keyBoardInput);
    if (keyBoardInput[0] == 'q' && keyBoardInput[1] == '\0') {
      return 0;
    }
    for (int i = 0;keyBoardInput[i] != '\0'; i++) {
      Character *newCharacter;
      newCharacter = (Character*) malloc(sizeof(Character));
      newCharacter -> data = keyBoardInput[i];
      newCharacter -> nextAddress = NULL;
		newCharacter -> addressCount = 0;
      if (rootCharacter == NULL) {
		  rootCharacter = newCharacter;
		  printf("put the [%c] as root\n", keyBoardInput[i]);
		  continue;
      } else {
		  Character *searchResults = searchEndCharacter(rootCharacter, keyBoardInput[i]);
		  if (searchResults -> nextAddress == NULL) {
			 searchResults -> nextAddress = newCharacter;
			 searchResults -> addressCount++;
			 printf("put the [%c] behind [%c]\n", keyBoardInput[i], searchResults -> data);
		  } else {
			 Character* tmp = (Character*) realloc(searchResults -> nextAddress, sizeof(Character));
			 if (tmp == NULL) {
				printf("memory error\n");
				free(searchResults);
				return -1;
			 } else {
				printf("put the [%c] branch from [%c]\n", keyBoardInput[i], searchResults -> data);
				searchResults -> nextAddress = tmp;
				searchResults -> addressCount++;
			 }
		  }
      }
    }
  }
  free(rootCharacter);
  return 0;
}

Character* searchEndCharacter(Character *c, char ch) {
  if (c -> nextAddress == NULL || c -> addressCount == 0) {
	 return c;
  } else {
	 for (int i = 0; i < c -> addressCount; i++) {
		if (c -> nextAddress[i].data == ch) {
		  searchEndCharacter(&c -> nextAddress[i], ch);
		}
	 }
	 return c;
  }
}

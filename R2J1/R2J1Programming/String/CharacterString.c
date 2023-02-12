#include <stdio.h>

void space_delete(char s[], int size) {
  int count = 0;
  for (int i = 0;  i < size; i++) {
    if (s[i] == ' ') {
      continue;
    } else {
      s[count] = s[i];
      count++;
     }
  }
}

void getWords(char s[], int size) {
  for (int i = 0; i < size; i++) {
    if (s[i] == ' ') {
      printf("\n");
      continue;
    } else {
      printf("%c", s[i]);
    }
  }
}

int main () {
  char s[] = "This is a pen";
  int size = sizeof(s);
  printf("%s\n", s);
  //space_delete(s, size);
  //printf("%s\n", s);
  getWords(s, size);
  return 0;
}


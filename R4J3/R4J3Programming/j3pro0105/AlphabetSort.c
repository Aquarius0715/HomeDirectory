#include <stdio.h>

#define MAX_RADIX 7

typedef struct String {
  char str[1024];
} String;

typedef enum SortOrder {
  ASCENDING,
  DESCENDING
} SortOrder;

void radixSort(String string[], int count, SortOrder E_sortOrder);
void showData(String string[], int count);

int main(void) {
  String stringArray[] = {{"the"}, {"five"}, {"five"}, {"boxing"}, {"wizards"}, {"jump"}, {"quickly"}};
  int count = 6;
  showData(stringArray, count);
  radixSort(stringArray, count, ASCENDING);
  showData(stringArray, count);
  return 0;
}

void radixSort(String string[], int count, SortOrder E_sortOrder) {
  int currentDigit = 0;
  char rad[count];
  String temp[count];
  while (currentDigit < MAX_RADIX) {
	 for (int i = 0; i < count; i++) {
		rad[i] = string[i].str[currentDigit];
		printf("%c ", string[i].str[currentDigit]);
	 }
	 printf("\n");
	 int k = 0;
	 for (char c = 0; c < ('z' - 'a'); c++) {
		for (char j = 0; j < count; j++) {
		  if (rad[j] == ('a' + c)) {
			 temp[k] = string[j];
			 k++;
		  }
		}
	 }
	 for (int i = 0; i < count; i++) {
			 string[i] = temp[i];
	 }
	 currentDigit++;
  }
}

void showData(String stringArray[], int count) {
  for (int i = 0; i < count; i++) {
	 printf("%s ", stringArray[i].str);
  }
  printf("\n");
}

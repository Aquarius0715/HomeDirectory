#include <stdio.h>

void swap(int *x, int *y);
void selection_sort(int array[], int array_size);

int main() {
  int a[] = {1, 2, 3, 4, 8, 6, 5, 7, 9, 11, 12, 13, 14, 16, 18, 20, 21};
  int size = (int) sizeof(a) / sizeof(int);
  int count = 0;
  selection_sort(a, size);
  for (int i = 0; i < size; i++) {
    if (a[i + 1] - a[i] == 1) {
      printf("%d", a[i]);
      i++;
      for (;;i++) {
	count++;
	if (a[i + 1] - a[i] == 1) {
	  continue;
	} else {
	  printf("-%d, ", a[i]);
	  break;
	}
      }
    } else {
      printf("%d, ", a[i]);
    }
  }
  printf("\n");
  return 0;
}

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int array[], int array_size) {
  int i, j, min, min_index;
  for (i = 0; i < array_size - 1; i++) {
    min = array[i];
    min_index = i;
    for (j = i + 1; j < array_size; j++) {
      if (array[j] < min) {
	min = array[j];
        min_index = j;
      }
    }
    swap(&array[min_index], &array[i]);
  }
}

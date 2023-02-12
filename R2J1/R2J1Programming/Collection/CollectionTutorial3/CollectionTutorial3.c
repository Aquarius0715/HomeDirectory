#include<stdio.h>

int main() {

  int i, j, k;

  int a[10] = {0, 2, 4, 6, 7, 7, 7 ,6, 4, 2};


  for (k = 0; k < 2; k++) {

    for (i = 0; i < 10; i++) {

      for (j = 0; j < a[i]; j++) {


	if (j == (a[i] -1)) {

	  printf("*");

	} else {

	printf(" ");

	}

      }

      printf("\n");

    }


  }

  return 0;


}

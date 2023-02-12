#include <stdio.h>

void triangles(int k) {

  for (int i = 0; i < 5; i++) {
    for (int ii = 0; ii < k; ii++) {
      for (int iii = 0; iii < 6; iii++) {

	if (5 - i > iii) {

	  printf(" ");

	} else {

	  printf("*");
	
	}
      
      }

    }

    printf("\n");
    
  }

}

int main () {

  //reusyuumonndai 2
  //triangles(2);

  //rensyuumondai 3

  for (int i = 0; i < 3; i++) {

    triangles(i + 1);
    
  }

  return 0;
  
}

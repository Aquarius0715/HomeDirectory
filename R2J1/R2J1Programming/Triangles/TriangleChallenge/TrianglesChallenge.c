#include <stdio.h>

void triangles(int k) {

  for (int i = 0; i < 5; i++) {

    for (int ii = 0; ii < 6*k; ii++) {

      if (ii < i) {

	printf("*");
      
      } else {

	printf(" ");
	
      }
    
    }

    printf("\n");
  
  }

}

int main () {

  triangles(1);

  return 0;
  
}

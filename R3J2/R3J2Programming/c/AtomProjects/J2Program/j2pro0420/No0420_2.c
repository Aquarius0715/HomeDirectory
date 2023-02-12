#include <stdio.h>

int main () {
  
  int nums[10] = {};

  int all = 0;
  int i = 0;
  int ii = 0;
  int n = 1;

  while (i < 10) {
  
    nums[i] = n;

    n += 2;

    i++;
    
  }

  printf("hairetu ni haitteru banngou\n");
    
  while (ii < 10) {

    printf("%d\n", nums[ii]);

    all += nums[ii];
    
    ii++;
    
  }

  printf("goukei ha %d desu\n", all);

}

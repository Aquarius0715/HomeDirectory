#include <stdio.h>
#include <stdlib.h>

int main() {

  int num;

  printf("数字を入力してください -> ");
  scanf("%d", &num);

  int i = 0;
  int h = num;
  while (h != 0) {
    h /= 2;
    i++;    
  }
  
  int *binary = (int *)malloc(sizeof(int)*i);

  for (int j = 0; j < i; j++) {
    binary[j] = num % 2;
    num /= 2;
  }

  for (int k = 0; k < i; k++) {
    printf("%d",binary[k]);  
  }

  printf("\n");

  return 0;
}

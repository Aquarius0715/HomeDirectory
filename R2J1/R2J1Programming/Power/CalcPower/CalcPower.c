#include <stdio.h>

int power(int k) {

  return k * k;
  
}

int main () {

  int k = 0;

  printf("Type some number! \n number: "); scanf("%d", &k);
  
  printf("%d no nijouha %d desu.\n", k, power(k));

  return 0;

}

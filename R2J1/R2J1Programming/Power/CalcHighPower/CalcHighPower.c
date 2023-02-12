#include <stdio.h>
#include <math.h>

double high_power(double x, double r) {

  double d = pow (x, r);
  
  return d;
  
}

int main () {

  double x = 0;
  double r = 0;

  printf("Type some number!!\n x: "); scanf("%lf", &x);
  printf("r:  "); scanf("%lf", &r);

  printf("%d no %d jou ha %lf desu.\n", x, r, high_power(x, r));

  return 0;
  
}

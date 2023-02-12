#include <stdio.h>
#include <math.h>

int v = 30;
double grav = 9.80665;
int theta;

int main () {

  printf("Type number: "); scanf("%d", theta);

  double x = v * v * cos(theta) * sin(theta);

  printf("%d\n", x);

  return 0;
  
}

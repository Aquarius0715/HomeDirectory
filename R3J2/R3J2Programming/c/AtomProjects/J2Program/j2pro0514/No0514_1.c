#include <stdio.h>

double yardToMeters(int yard) {

  return yard * 0.9144;

}

int main () {

  double yard;

  printf("Input your number: "); scanf("%lf", &yard);

  printf("%f yards = %f meters\n", yard, yardToMeters(yard));
  
  return 0;
  
}

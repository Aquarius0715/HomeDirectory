#include <stdio.h>

double pondToKilogram(double pond) {

  return pond * 0.453592;

}

int main () {

  double pond;
  
  printf("Input your pond: "); scanf("%lf", &pond);

  printf("%f pond = %f kg\n", pond, pondToKilogram(pond));

  return 0;
  
}

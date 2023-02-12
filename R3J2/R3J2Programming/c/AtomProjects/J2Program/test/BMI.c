#include <stdio.h>

double calc_BMI(double weight, double height);
double get_weight();
double get_height();
void print_title();
void print_result(double result);

int main () {

  print_title();

  double weight = get_weight();
  double height = get_height();

  print_result(calc_BMI(weight, height));

  printf("%f %f\n", weight, height);

return 0;

}

void print_title() {

  printf("Calc BIM Program!!\n");

}

double get_weight() {

  int weight;

  printf("Type Your Weight: ");
  scanf("%lf", &weight);

  return weight;

}

double get_height() {

  int height;

  printf("Type Your Height: ");
  scanf("%lf", &height);

  return height;

}

double calc_BMI(double weight, double height) {

  return weight / (height * height);

}

void print_result(double result) {

  printf("Your BMI is %f.\n", result);

}

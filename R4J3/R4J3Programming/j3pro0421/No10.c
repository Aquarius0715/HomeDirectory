#include <stdio.h>
float TotalTime(float TimeForEach[]);

int main() {
  float TimeToAnswer, TimeForEach[] = {7, 8.5, 3.5, 2.5, 2, 5.5, 3, 4, 3.5};
  // first question
  TimeToAnswer = TotalTime(TimeForEach);
  printf("Time Required = %.2f", TimeToAnswer);
  return 0;
}

float TotalTime(float TimeForEach[]) {
  int i;
  float sum = 0.0;

  //second question
  for (int i = 0; i < 9; ++i) {
    // third question
    sum += TimeForEach[i];
  }
  return sum;
}

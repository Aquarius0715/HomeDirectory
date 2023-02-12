#include <stdio.h>
#include <stdlib.h>

#define NUM 10

struct status {
  int no;
  int japanese;
  int english;
  int math;
};

void initialize(struct status students[]);
void disp(struct status students[]);
void individual(struct status person);

int main(void)
{
  struct status students[NUM];
  
  srand(204);

  initialize(students);
  disp(students);
  individual(students[3]);
  
  return 0;
}

void initialize(struct status students[])
{
  int i;

  for (i=0; i<NUM; i++) {
    students[i].no = 4401+i;
    students[i].japanese = rand()%101;
    students[i].english = rand()%101;
    students[i].math = rand()%101;
  }
}

void disp(struct status students[])
{
  int i;

  printf("No    Ja  En  Ma\n");
  for (i=0; i<NUM; i++) {
    individual(students[i]);
  }
  printf("\n");
}

void individual(struct status person)
{
  printf("%d %3d %3d %3d\n",
	 person.no,
	 person.japanese,
	 person.english,
	 person.math);
}

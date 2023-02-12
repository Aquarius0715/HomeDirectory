#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 10
#define NAME 8+1

struct parameter {
  int no;
  char name[NAME];
  int hp;
  int mp;
  double attack;
  double defence;
};

void initialize(struct parameter player[]);
void disp_array(struct parameter player[]);

int main(void)
{
  struct parameter player[PLAYER];
  int seed;

  seed = (unsigned)time(NULL);
  printf("seed = %d\n", seed);
  srand(seed);

  initialize(player);

  disp_array(player);

  return 0;
}

void initialize(struct parameter player[])
{
  int i, j;

  for (i=0; i<PLAYER; i++) {
    player[i].no = i+1;
    for (j=0; j<NAME-1; j++) { 
      player[i].name[j] = 'a'+rand()%26;
    }
    player[i].name[j] = '\0';
    player[i].hp = rand()%100+1;
    player[i].mp = rand()%101;
    player[i].attack = (double)rand()/RAND_MAX;
    player[i].defence = (double)rand()/RAND_MAX;
  }

}

void disp_array(struct parameter player[])
{
  int max_index;
  int max_atk = player[0].attack;

  printf("MAX ATK GETTER\n");
  printf("No   Name      HP  MP  AT    DE \n");
  /*
  for (i=0; i<PLAYER; i++) {
    printf("[%2d] ", player[i].no);
    printf("%s", player[i].name);
    printf(" ");
    printf("%3d %3d  %.2f  %.2f\n", 
	   player[i].hp, player[i].mp, player[i].attack, player[i].defence);
  }
  */
  for (int i = 0; i < PLAYER; i++) {
    if (max_atk > player[i].attack) {
      max_atk = player[i].attack;
      max_index = i;
    } else {
      continue;
    }
  }
  printf("[%2d] ", player[i].no);
  printf("%s", player[i].name);
  printf(" ");
  printf("%d3 %3d  %.3f  %.2f\n",
    player[i].hp, player[i].mp, player[i].attack, player[i].defence);
}


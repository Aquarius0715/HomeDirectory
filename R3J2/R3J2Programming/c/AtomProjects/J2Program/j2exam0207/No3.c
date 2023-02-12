#include <stdio.h>
#include <stdlib.h>

#define NUM 20
#define NAME 10

struct products {
  int no;			/* 商品番号 */
  int price;			/* 価格 */
  int country_No;		/* 生産国番号 */
  char country_Name[NAME];	/* 生産国の名前 */
  int year;			/* 発売年 */
};

void initialize(struct products item[]);
void disp(struct products item[]);

int main(void)
{
  struct products car[NUM];
  struct products bike[NUM];
  
  srand(206);

  initialize(car);
  initialize(bike);

  printf("-- Car --\n");
  disp(car);

  printf("-- Bike --\n");
  disp(bike);

  return 0;
}

void initialize(struct products item[])
{
  int i;

  for (i=0; i<NUM; i++) {
    item[i].no = rand()%1000;
    item[i].price = rand()%100000;
    item[i].country_No = rand()%5;
    item[i].year = 1990 + rand()%(2017-1990);
  }

  /* 生産国番号から名前を決定 */
  for (i=0; i<NUM; i++) {
    if (item[i].country_No == 0) {
      sprintf(item[i].country_Name, "Japan");
    }
    else if (item[i].country_No == 1) {
      sprintf(item[i].country_Name, "America");
    }
    else if (item[i].country_No == 2) {
      sprintf(item[i].country_Name, "Itary");
    }
    else if (item[i].country_No == 3) {
      sprintf(item[i].country_Name, "France");
    }
    else {
      sprintf(item[i].country_Name, "Other");
    }
  }
}

void disp(struct products item[])
{
  int i, j;

  printf("No    Price   Country   year\n");
  for (i=0; i<NUM; i++) {
    printf("%3d   %5d   %-8s  %4d\n",
	   item[i].no,
	   item[i].price,
	   item[i].country_Name,
	   item[i].year);
  }
  printf("\n");
}

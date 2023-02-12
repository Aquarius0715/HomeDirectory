#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int stats[N];
const char label[N][4] = {"HP", "MP", "ATK", "DEF", "AGI"};

void init() {

  srand((unsigned)time(NULL));

  for (int i = 0; i < N; i++) {

    stats[i] = 0;

  }
  
}

void sendMessage() {

  printf("The RPG Start!!!\n");
  
}

int Random(int n) {

  return rand() % n; 
  
}

int getSeed() {

  int n;
  
  do {

    printf("Input your like number: "); scanf("%d", &n);
    
  } while (n < 1 || n > 10000);

  return n;
  
}

int getStats() {

  for (int i = 0; i < 5; i++) {

    if (i < 2) {

      stats[i] = Random(10000);
      
    } else {

      stats[i] = Random(100);
      
    }
    
  }
  
}

int showStats() {

  printf("==========Your Stats==========\n");

  for (int i = 0; i < N; i++) {

    printf("%s: %d\n", label[i], stats[i]);
    
  }

  printf("==============================\n");
  
}

int main () {
  
  init();

  sendMessage();

  getSeed();

  getStats();

  showStats();
  
  return 0;
  
}

#include <stdio.h>

int main () {

  int age = 0;
  
  printf("〇〇動物園へようこそ！\n");
  printf("まず、年齢を教えてください。\n");

  while (1) {

    scanf("%d", &age);

    if (age < 0 || age > 110) {
      printf("もう一度年齢を教えてください。\n");
      continue;
    } else {
      break;
    }
  }

  if (age < 6) {
    
    printf("%d才ですね！それなら入場料は無料です。\n");
  } else if (age >= 6 && age < 12) {
    
    printf("%d才ですね！入場料は350円です。\n", age);
  } else if (age > 12) {
    
    printf("%d歳ですね！入場料は700円です。\n", age);
  }

  return 0;
  
}

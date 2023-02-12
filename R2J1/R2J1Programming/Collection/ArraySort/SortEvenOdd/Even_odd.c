#include <stdio.h>
#define N 10

int henkan (int i) {

  if (i % 2 == 0) {

    return i / 2;

  } else {

    if (N % 2 == 0) {

      return df
      
    }
    
  }
  
}

void array_copy(int b[], int a[]) {

  for (int i = 0; i < N; i++) {

    b[i] = a[i];
    
  }
  
}

void even_odd(int a[]) {

  int tmp[N];

  for (int i = 0; i < N; i++) {

    tmp[i] = a[henkan(i)];

  }
  
    array_copy(a, tmp);
    
}

void array_printf(int a[]) {

  for (int i = 0; i < N; i++) {

    printf("%d", a[k]);
    
  }
  
}

int main () {

  int a[N];

  for (int i = 0; i < N; i++) {

    a[i] = i;
    
  }

  even_odd(a);

  array_printf(a);

  return 0;
  
}
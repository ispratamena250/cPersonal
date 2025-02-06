#include <stdio.h>

int main(){
  int v[6] = {1, 2, 3, 4, 5};

  int n = *(&v + 1) - v;
  printf("Size: %d\n", n);
  
  return 0;
}

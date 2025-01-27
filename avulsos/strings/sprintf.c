/*
 *  A função snprinf() também é interessante. 
 *  Possui a mesma ideia, mas permite especificar o tamanho do buffer.
 *
 *  Na linha 21 é usado o 'especificador de largura variável'. 
 * */

#include <stdio.h>

int main(){ 
  int z = 10, z2 = 2;
  char c[10];

  printf("%d\n", z);
  sprintf(c, "%d\n", z+z2);
  printf("%s\n", c);

  for(int i=0; i<5; i++){
    char c2[50];
    int num = 42;
    sprintf(c2, "%0*d", i+3, num);
    printf("%s\n", c2);
  }

  return 0;
}

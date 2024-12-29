/*
 * C program to convert any decimal number with any size to a binari number
 * Run like this: gcc -Wall largeConvBinDec.c -o largeCovnBinDec.x
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){ //Código descontinuado.
  if(argc != 2){
    printf("Erro! Compile assim: $ ./largeConvBinDec.x n\n");
    exit(1);
  }

  char divd[2] = "2"; //Dividendo
  char n[100];
  strcpy(n, argv[1]);
  int len1 = strlen(n);
  int len2 = strlen(divd);

  printf("n antes: %s\n", n);
  for(int i = len1 - 1; i>= 0; i--){
    if(i == len1-1){
      int digit = (n[i] - '0') - (divd[len2-1] - '0');
      printf("linha 26: n: %d divd: %d\n", n[i]-'0', divd[len2-1]-'0');
      n[i] = (digit + 10);
      int digit2 = n[i-1] - '0';
      printf("i-1: %d digit2: %d\n", n[i-1], digit2-1);
      printf("linha 28: %d digit: %d\n", (digit + 10), digit);
    }
  }
  printf("n depois: %s\n", n);

  printf("\n");
  return 0;
}

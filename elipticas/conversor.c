/*
 * C program to quickly convert numbers into other bases.
 * Compile: $ gcc -Wall conversorBinario.c -lmgp -o conversorBinario.x 
 * Run: $ ./conversorBinario.x n
 * */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void decBin();
void binDec();

int main(){
  int op;
  printf("1 - Dec -> Bin\n2 - Bin -> Dec\nOption: ");
  scanf("%d", &op);

  switch(op){
    case 1:
      printf("\nDec -> Bin\nNumber: ");
      char nd[50];
      scanf("%s", nd);
      decBin(nd);
      break;
    case 2:
      printf("\nBin -> Dec\nNumber: ");
      char nb[50];
      scanf("%s", nb);
      binDec(nb);
      break;
  }

  printf("\n");
  return 0;
}

void decBin(char *nd){
  mpz_t n;
  mpz_init(n);
  mpz_set_str(n, nd, 10);

  char *bin = mpz_get_str(NULL, 2, n);
  printf("%s\n", bin);
  
  mpz_clear(n);
  free(bin);
}

void binDec(char *nb){
  mpz_t n;
  mpz_init(n);
  mpz_set_str(n, nb, 2);

  char *dec = mpz_get_str(NULL, 10, n);
  printf("%s\n", dec);

  mpz_clear(n);
  free(dec);
}

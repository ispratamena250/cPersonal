/*
 *  C program to create a desired truth table
 *  Compile: $ gcc -Wall tabelaVerdade.c -lm -lgmp -o tabelaVerdade.x
 *  Run: ./tabelaVerdade.x var
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int main(int argc, char *argv[2]){
  if(argc != 2){
    printf("Erro! Run: $ ./tabelaVerdade.x var\n");
    exit(1);
  }

  char var = atoi(argv[1]);
  mpz_t n;
  mpz_init(n);

  for(int i=0; i<=(int)pow(2, var); i++){
    char aux[50];
    sprintf(aux, "%d", i);
    mpz_set_str(n, aux, 10);
    char *bin = mpz_get_str(NULL, 2, n);
    printf("%s\n", bin);

    free(bin);
  }
  
  mpz_clear(n);

  printf("\n");
  return 0;
}

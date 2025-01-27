/*
 *  C program to create a desired truth table
 *  Compile: $ gcc -Wall tabelaVerdade.c -lm -lgmp -o tabelaVerdade.x
 *  Run: ./tabelaVerdade.x var
 *  To download libgmp: sudo apt install libgmp-dev
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

//Signature
int lastLine_numOfBits();

int main(int argc, char *argv[2]){ //Para valores muito altos, como 45, faltam ajustes
  if(argc != 2){
    printf("Erro! Run: $ ./tabelaVerdade.x var\n");
    exit(1);
  }

  char var = atoi(argv[1]);
  mpz_t n;
  mpz_init(n);

  int aux_lastLine = atoi(argv[1]);
  int last = lastLine_numOfBits(aux_lastLine);

  for(int i=0; i<(int)pow(2, var); i++){
    char aux[100];
    sprintf(aux, "%d", i);
    mpz_set_str(n, aux, 10);
    char *bin = mpz_get_str(NULL, 2, n);
    int aux_sprintf = atoi(bin);

    char c[100];
    sprintf(c, "%0*d", last, aux_sprintf);
    printf("%do -> %s\n", i, c);

    free(bin);
  }
  
  mpz_clear(n);

  printf("\n");
  return 0;
}

/*
 *  A function that find the number of bits of the last line of the truth table
 * */
int lastLine_numOfBits(int z){ 
    int aux = (int)pow(2, z-1);
  char s[100];
  sprintf(s, "%d", aux);

  mpz_t n;
  mpz_init(n);

  mpz_set_str(n, s, 10);
  char *bin = mpz_get_str(NULL, 2, n);
  int size = strlen(bin);

  mpz_clear(n);
  free(bin);

  return size;
}

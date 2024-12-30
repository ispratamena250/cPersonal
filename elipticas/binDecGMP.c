/*
 * C program to convert a decimal number into a binari number with GMP(GNU)
 * Compile: $ gcc -Wall binDecGMP.c -lgmp -o binDecGMP.x
 * Run: $ ./binDecDMP.x
 *
 * To downlaod: sudo apt install libgmp-dev
 *
 * Breath tutorial:
 * Principais tipos da GMP:
 * mpz_t (inteiro)
 * mpq_t (frações)
 * mpf_t (ponto flutuante)
 * 
 * Operações básicas:
 * mpz_t num;
 * mpz_init(num); //Inicializa
 * mpz_clear(num); //Libera memória
 *
 * Atribuir valores:
 * mpz_set_ui(num, 123456); //Atribui valor inteiro
 * mpz_set_str(num, "6498462168435546843548984", 10); //Atribui valor na base 10
 *
 * Operações matemáticas:
 * mpz_add(result, op1, op2);  // result = op1 + op2
 * mpz_sub(result, op1, op2);  // result = op1 - op2
 * mpz_mul(result, op1, op2);  // result = op1 * op2
 * mpz_div(result, op1, op2);  // result = op1 / op2
 *
 * Ferramentas avançadas:
 * Comparação:
 * int cmp = mpz_cmp(num1, num2);  // Retorna <0, 0, ou >0
 * Potências e raizes:
 * mpz_pow_ui(result, base, exp); // result = base^exp
 * mpz_sqrt(result, num);         // result = sqrt(num)
 *
 * Operações modulares:
 * mpz_mod(result, num, mod);     // result = num % mod
 * mpz_powm(result, base, exp, mod); // result = base^exp % mod
 *
 * Geração aleatória de números:
 * gmp_randstate_t state;
 * gmp_randinit_default(state);   // Inicializar o gerador de números aleatórios
 * mpz_urandomb(result, state, 128); // Gera um número de até 128 bits
 * gmp_randclear(state);          // Limpa o gerador
 * */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char *argv[]){ //First program using GMP
  mpz_t n;
  mpz_init(n);
  
  mpz_set_str(n, "13446657929821834091822994051619975732744628822443545947364646763437621316310777251047705180966521414747598675390697689127135788929505254233785056735649562131145017733358757254047521677903219931704042039776370054411324665861933559952859489614057400898574869234132639587660077838017884372215920384264120259932735614063214028059697001346261756220826379971898967880934882958890804633652952840740734412639430610176431958334308581925380453514523399604437889639053502759000675136096649527512417888255177354", 10);
  char *bin = mpz_get_str(NULL, 2, n);

  printf("%s",bin);

  mpz_clear(n);
  free(bin);

  printf("\n");
  return 0;
}

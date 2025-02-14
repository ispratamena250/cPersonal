#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char* argv[]){
  mpz_t i, limit, one;

  mpz_init_set_ui(i, 0);
  mpz_init_set_ui(limit, 10);
  mpz_init_set_ui(one, 1);

  for(; mpz_cmp(i, limit) < 0; mpz_add(i, i, one)){
    gmp_printf("%Zd\n", i);
  }

  mpz_clear(i);
  mpz_clear(limit);
  mpz_clear(one);

  printf("\n");
  return 0;
}

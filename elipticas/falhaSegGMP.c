#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(){
	mpz_t z;
	mpz_init(z);

	char s[100];

	printf("Digite: ");
	scanf("%s", s);

	mpz_set_str(z, s, 10);

	gmp_printf("%Zd\n", z);

	mpz_clear(z);

	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char* argv[3]){
	if(argc != 3){
		printf("Erro! Forneca: s_zaux2 & s_zaux3\n");
		exit(1);
	}

	FILE *file1 = fopen("operacoesGMP.dat", "w");
	if(!file1){
		printf("Erro\n");
		exit(1);
	}

	mpz_t i, limit, one, var, p, result_varModp, zaux, zaux2, zaux3;
	int z1;
	printf("Insira z1: ");
	scanf("%d", &z1);
	int s_zaux2 = atoi(argv[1]);
	char *s_zaux3 = argv[2];

	mpz_init_set_ui(i, 0);
	mpz_init_set_ui(limit, 10);
	mpz_init_set_ui(one, 1);
	mpz_init_set_ui(var, 99);
	mpz_init_set_ui(p, 13);
	mpz_init(result_varModp);
	mpz_init_set_ui(zaux, z1);
	mpz_init_set_ui(zaux2, s_zaux2);
	mpz_set_str(zaux3, s_zaux3, 10);

	for(; mpz_cmp(i, limit) < 0; mpz_add(i, i, one)){
		gmp_printf("%Zd\n", i);
	}

	mpz_mod(result_varModp, var, p);
	gmp_printf("var mod p: %Zd\n", result_varModp);

	char s1[100];
	char s2[100];
	char s3[100];
	mpz_get_str(s1, 10, var);
	mpz_get_str(s2, 10, p);
	mpz_get_str(s3, 10, result_varModp);

	fprintf(file1, "%s\t%s\t%s\n", s1, s2, s3);

	gmp_printf("zaux: %Zd\n", zaux);

	gmp_printf("zaux2: %Zd\n", zaux2);

	gmp_printf("zaux3: %Zd\n", zaux3);

	mpz_clear(i);
	mpz_clear(limit);
	mpz_clear(one);
	mpz_clear(var);
	mpz_clear(p);
	mpz_clear(result_varModp);
	mpz_clear(zaux);
	mpz_clear(zaux2);
	mpz_clear(zaux3);
	fclose(file1);

	system("cat operacoesGMP.dat");
	system("rm operacoesGMP.dat");

	printf("\n");
	return 0;
}

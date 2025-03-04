/*
 * Progama para calcular o inverso modular entre dois números
 */
#include <stdio.h>
#include <stdlib.h>

//Assinatura
int gcdExtended();
int modInverse();
int gcdClassic();

int main(int argc, char* argv[]) {
	int orderUn=0;

	if(argc != 2){
		printf("Erro! Execute como: ./inversoModular m\n");
		exit(1);
	}    

	int m = atoi(argv[1]);
	int *v = (int *)calloc(m-1, sizeof(int));
	if(v == NULL){
		printf("Alocation error!\n");
		exit(1);
	}

	printf("Classe de equivalência Z%d e inversos:\n", m);
	for(int i=1; i<m; i++){
		int inverse = modInverse(i, m);
		if(inverse != -1){
			printf("Inverso de %d mod(%d) = %d\n", i, m, inverse);
			if(gcdClassic(inverse, m) == 1){
				orderUn++;
				v[i] = inverse;
			}
		}
	}

	printf("U%d = ", m);
	for(int i=0; i<m; i++){
		if(v[i] != 0){
			printf("%d ", v[i]);
		}
	}
	printf("\nOrdem de U%d: %d (phi function)", m, orderUn);

	free(v);

	printf("\n");
	return 0;
}

int gcdExtended(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // Coeficientes para as chamadas recursivas
	int gcd = gcdExtended(b % a, a, &x1, &y1); //Estudar sobre isso depois.

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int modInverse(int a, int m) {
	int x, y; // Coeficientes que satisfazem a identidade de Bézout
	int gcd = gcdExtended(a, m, &x, &y);

	if (gcd != 1) {
		printf("Inverso de %d mod(%d) não existe\n", a, m);
		return -1; // Retorna -1 para indicar que não há inverso
	}

	// Ajusta x para ser positivo (caso necessário)
	int inverse = (x % m + m) % m;
	return inverse;
}

int gcdClassic(int a, int m){
	int rest, count=1, aux;

	if(a < m){
		aux = a;
		a = m;
		m = aux;
	}

	while(m != 0){
		rest = a % m;
		a = m;
		m = rest;
		count++;
	}

	return a;
}

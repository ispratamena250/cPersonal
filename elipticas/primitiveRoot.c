/*
 * C program to compute the order of each element in Z_p
 *   
 * Compile: $ gcc -Wall primitiveRoot.c -o primitiveRoot.x
 * Run:     $ ./primitiveRoot.x <prime number>
 * */

#include <stdio.h>
#include <stdlib.h>

static int mod_pow(int base, int exp, int mod) {
	int result = 1;
	base %= mod;

	while (exp > 0) {
		if (exp & 1)
			result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error. Run: $ ./primitiveRoot.x <prime number>\n");
		return 1;
	}

	int p = atoi(argv[1]);

	printf("Element in Zp -> its order\n");
	for (int i = 1; i < p; i++) {
		int order = 1;
		while (mod_pow(i, order, p) != 1)
			order++;
		printf("%d -> %d\n", i, order);
	}

	return 0;
}


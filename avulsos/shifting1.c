/*
 * Deslocamento para esquerda: equivalente a x * 2^n
 * Deslocamento para a direita: para inteiros sem sinal, zeros são adicionados. Para 
 * inteiros com sinal, depende do compilador. Às vezes o bit de sinal é repetido.
 * */
#include <stdio.h>

int main(){
	unsigned int a = 7;
	unsigned int b = 7 << 1; //b * 2^n

	printf("%d -> %d\n", a, b);
	printf("a & b = %d\n", a&b);
	printf("a | b = %d\n", a|b);
	printf("a ^ b = %d\n", a^b);
	printf("~a = %d\n", ~a);

	printf("\n");
	return 0;
}

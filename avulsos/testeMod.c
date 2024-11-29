#include <stdio.h>

int main(){
	int a=-14, b=17;

	printf("%d\n", a%b); //Não funciona em C para um a negativo
	printf("%d\n", (a % b + b) % b);

	return 0;
}

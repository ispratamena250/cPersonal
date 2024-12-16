#include <stdio.h>

int main(){
	char nome[10];

	printf("Digite o nome: ");
	scanf("%s", nome);
	printf("Nome: %s\n", nome);

	/*for(int i=0; i<10; i++){ //Não funciona
		printf("%s ", nome);
	}
	printf("\n");*/ 

	return 0;
}

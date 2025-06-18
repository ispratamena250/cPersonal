#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pilhaHeader.h"
#include "filaHeader.h"

//Prototypes
void produzir();
void distribuir();

int main(){
	int op = 0;

	printf("Opcoes:\n1 - Produzir marmitas\n2 - Distribuir marmitas\nEscolhe: ");
	scanf("%d", &op);
	switch(op){
		case 1:
			produzir();
			break;
		case 2:
			distribuir();
			break;
		default:
			break;
	}

	printf("\n");
	return 0;
}

void produzir(){
	printf("produzindo");
}

void distribuir(){
	printf("distribuindo");
}

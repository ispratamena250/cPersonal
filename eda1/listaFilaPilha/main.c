#include <stdio.h>
#include <stdlib.h>
//#include "listaHeader.h"
//#include "filaHeader.h"
#include "pilhaHeader.h"

int main(){
	Pilha* p = cria();

	insere(p, 10);
	insere(p, 20);
	insere(p, 30);
	insere(p, 40);

	imprime(p);

	remover(p);

	printf("\n\n");
	imprime(p);

	printf("\n");
	return 0;
}

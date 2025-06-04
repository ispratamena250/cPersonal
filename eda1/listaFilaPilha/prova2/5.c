#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha Pilha;
typedef struct no No;

struct pilha{
	No* topo;
};

struct no{
	No* prox;
	int tempo;
	char roupa[51];
	char cor[51];
};

Pilha* cria(){ 
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void insere(Pilha* p, int z, char roupa[51], char cor[51]){
	No* novo = (No*) malloc(sizeof(No));
	novo->tempo = z;
	novo->roupa = roupa;
	novo->cor = cor;
	novo->prox = NULL;

	novo->prox = p->topo;
	p->topo = novo;
}

void listar(Pilha* p){
	int totalRoupas=0, totalTempo=0;
	for(No* no=p->topo; no!=NULL; no=no->prox){
		printf("Tipo: %s Cor: %s\n", no->roupa, no->cor);
		totalRoupas++;
		totalTempo += no->tempo;
	}
	printf("\nTotal de roupas = %d\n", totalRoupas);
	printf("\nTotal de tempo = %d\n", totalTempo);
}

int main(){
	char s1[51], s2[51], parada[] = "end";
	int z;
	Pilha* p = cria();

	do{
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%d", &z);
	}while(strcmp(s1, parada) != 1);

	listar(p);

	return 0;
}










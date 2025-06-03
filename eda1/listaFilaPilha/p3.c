#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct no No;

struct pilha{
	No* topo;
};

struct no{
	No* prox;
	No* item;
};

Pilha* cria(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void insere(Pilha* p, int z){
	No* novo = (No*) malloc(sizeof(No));
	//no->prox = NULL;
	no->item = z;

	novo->prox = p->topo;
	p->topo = novo;
}

int remover(Pilha* p, int z){
	if(p->topo == NULL){
		return 1;
	}

	No* no = p->topo;
	p->topo = no->prox;
	free(no);
	return 0;
}

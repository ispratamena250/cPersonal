#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct no No;

struct pilha{
	No* topo;
};

struct no{
	No* prox;
	int item;
};

Pilha* cria(){
	Pilha p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void push(Pilha* p, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->item = z;

	novo->prox = p->topo;
	p->topo = novo;
}

int pop(Pilha* p, int z){
	if(p->topo == NULL){
		return 1;
	}else{
		No* atual = p->topo;
		z = atual->item;
		p->topo = atual->prox;
		free(atual);
		return 0;
	}	
}

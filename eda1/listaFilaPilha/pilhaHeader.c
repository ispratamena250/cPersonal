#include <stdio.h>
#include <stdlib.h>
#include "pilhaHeader.h"

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
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void insere(Pilha* p, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->item = z;

	novo->prox = p->topo;
	p->topo = novo;
}

int remover(Pilha* p){
	if(p->topo == NULL){
		return 1;
	}else{
		No* atual = p->topo;
		//z = atual->item;
		p->topo = atual->prox;
		free(atual);
		return 0;
	}
}

int vazia(Pilha* p){
	if(p->topo == NULL)
		return 0;

	return 1;
}

int pertence(Pilha* p, int z){
	for(No* novo=p->topo; novo!=NULL; novo=novo->prox){
		if(novo->item == z) return 0;
	}

	return 1;
}

void imprime(Pilha* p){
	for(No* novo=p->topo; novo!=NULL; novo=novo->prox){
		printf("%d\n", novo->item);
	}
}




























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

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void insereItemPilha(Pilha* p, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->item = z;

	novo->prox = p->topo;
	p->topo = novo;
}

int removerItemPilha(Pilha* p, int z){
	if(p->topo == NULL){
		return 1;
	}else{
		No* atual = p->topo;
		atual->item = z;
		p->topo = atual->prox;
		free(atual);
		return 0;
	}
}

int vaziaPilha(Pilha* p){
	if(p->topo == NULL) 
		return 0;

	return 1;
}

int pertencePilha(Pilha* p, int z){
	for(No* no=p->topo; no!=NULL; no=no->prox)
		if(no->item == z)
			return 0;

	return 1;
}

void imprimePilha(Pilha * p){
	for(No* no=p->topo; no!=NULL; no=no->prox)
		printf("%d\n", no->item);
}

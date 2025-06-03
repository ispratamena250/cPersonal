#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct no No;

struct lista{
	No* prim;
};

struct no{
	No* prox;
	int item;
};

Lista* cria(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prim = NULL;

	return l;
}

void insere(Lista* l, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->prox = NULL;
	novo->item = z;

	if(l->prim == NULL){
		l->prim = novo;
	}else{
		No* atual = l->prim;
		while(atual->prox != NULL){
			atual = atual->prox;
		}
		atual->prox = novo;
	}
}

int remover(Lista* l, int z){
	No* atual = l->prim;
	No* anterior = NULL;

	while(atual != NULL){
		if(atual->item == z){
			if(anteior == NULL){
				l->prim = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
			return 0;
		}
		anterior = atual;
		atual = atual->prox;
	}

	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include "listaHeader.h"

typedef struct lista Lista;
typedef struct no No;

struct lista{
	No* prim;
};

struct no{
	int item;
	No* prox;
};

Lista* cria(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prim = NULL;

	return l;
}

void insere(Lista* l, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->item = z;
	novo->prox = NULL;

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

int remover(Lista* l){
	No* atual = l->prim;
	No* anterior = NULL;

	while(atual != NULL){
		if(atual->item == z){
			if(anterior == NULL){
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

void listar(Lista* l){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox){
		printf("%d ", novo->item);
	}
}

int buscar(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox){
		if(novo->item == z) return 0;
	}

	return 1;
}

int vazia(Lista* l){
	if(l->prim == NULL)
		return 0;

	return 1;
}

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

void remover(Lista* l, int z){
	No* atual = l->prim;
	No* ant = NULL;

	while(atual != NULL){
		if(atual->item == z){
			if(ant == NULL){
				l->prim = atual->prox;
			}else{
				ant->prox = atual->prox;
			}
			free(atual);
		}
		ant = atual;
		atual = atual->prox;
	}
}

int vazia(Lista* l){
	if(l->prim == NULL)
		return 0;
	else
		return 1;
}

int pertence(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox){
		if(novo->item == z) return 0;
	}

	return 1;
}

void imprime(Lista* l){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox){
		printf("%d ", novo->item);
	}
}

void libera(Lista* l){
	No* no = l->prim;

	while(no != NULL){
		No* atual = no->prox;
		free(no);
		no = atual;
	}
	free(l);
}

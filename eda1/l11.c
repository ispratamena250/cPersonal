#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct no No;

struct lista{
	No* prim;
};

struct no {
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
	No* anterior = NULL;
	
	while(atual != NULL){
		if(atual->item == z){
			if(anterior == NULL){
				l->prim = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
		}
		anterior = atual;
		atual = atual->prox;
	}
}

int libera(Lista* l){
	No* no = l->prim;

	while(no != NULL){
		No* atual = no->prox;
		free(no);
		no = atual;
	}
	free(l);
	return 0;
}







































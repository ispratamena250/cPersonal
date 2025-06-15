#include <stdio.h>
#include <stdlib.h>
#include "listaHeader.h"

typedef struct fila Fila;
typedef struct no No;

struct fila{
	No* prim;
	No* fim;
};

struct no{
	No* prox;
	int item;
}

Fila* cria(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->prim = NULL;
	f->fim = NULL;

	return f;
}

void insere(Fila* f, int z){
	No* novo = (No*) malloc(sizeof(No));
	novo->prox = NULL;
	novo->item = z;

	if(f->fim != NULL)
		f->fim->prox = novo;
	else
		f->prim = novo;
	
	f->fim = novo;
}

int remover(Fila* f, int z){
	if(f->prim == NULL)
		return 1;

	No* no=f->prim;
	f->prim = no->prox;
	if(f->prim == NULL)
		f->prim = NULL;

	free(no);
	return 0;
}

int vazia(Fila* f){
	if(f->prim == NULL)
		return 0;

	return 1;
}

void imprime(Fila* f){
	for(No* no=f->prim; no!=NULL; no=no->prox)
		printf("%d ", no->item);
}

int pertence(Fila* f, int z){
	for(No* no=f->prim; no!=NULL; no=no->prox)
		if(no->item == z)
			return 0;

	return 1;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct no No;

struct fila{
	No* inicio;
	No* fim;
};

struct no{
	No* prox;
	int item;
};

Fila* cria(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;

	return f;
}

void insere(Fila* f, int z){
	No* novo = (No*) malloc(sizeof(No));
	no->item = z;
	no->prox = NULL;

	if(f->fim != NULL){
		f->fim->prox = novo;
	}else{
		f->inicio = novo;
	}
	f->fim = novo;
}

int remover(Fila* f, int z){
	if(f->inicio == NULL){
		return 1;
	}

	No* no = f->inicio;
	f->inicio = no->prox;
	if(f->inicio == NULL){
		f->inicio = NULL;
	}
	free(no);
	return 0;
}





































































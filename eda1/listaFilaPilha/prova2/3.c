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
	novo->prox = NULL;
	novo->item = z;

	if(f->fim != NULL){
		f->fim->prox = novo;
	}else{
		f->inicio = novo;
	}
	f->fim = novo;
}

void listar(Fila* f){
	int i=0;
	printf("Fila geral original\n");
	for(No* no=f->inicio; no!=NULL; no=no->prox){
		printf("%d - %d\n", i+1, no->item);
		i++;
	}

	i=0;
	printf("\n\nFila preferencial\n");
	for(No* no=f->inicio; no!=NULL; no=no->prox){
		if(no->item >= 60){
			printf("%d - %d\n", i+1, no->item);
		}
		i++;
	}

	i=0;
	printf("\n\nFila geral atualizada\n");
	for(No* no=f->inicio; no!=NULL; no=no->prox){
		if(no->item < 60){
			printf("%d - %d\n", i+1, no->item);
		}
		i++;
	}

	int j=0;
	i=0;
	printf("\n\nResultado esperado fila preferencial\n");
	for(No* no=f->inicio; no!=NULL; no=no->prox){
		if(no->item >= 60){
			printf("%d - %d\n", j+1, i+1);
			j++;
		}
		i++;
	}

	i=0;
	j=0;
	printf("\n\nResultado esperado fila geral\n");
	for(No* no=f->inicio; no!=NULL; no=no->prox){
		if(no->item < 60){
			printf("%d - %d\n", j+1, i+1);
			j++;
		}
		i++;
	}
}

int main(){
	Fila* f = cria();

	int z;
	do{
		scanf("%d", &z);
		insere(f, z);
	}while(z != 0);

	listar(f);

	return 0;
}

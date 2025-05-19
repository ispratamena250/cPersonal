#include <stdio.h>
#include <stdlib.h>

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

int remover(Lista* l, int z){
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

int main(){
	Lista* l = cria();

	printf("\nVazia:\n");
	int v1 = vazia(l);
	printf("%d", v1);

	insere(l, 10);
	insere(l, 20);
	insere(l, 30);
	insere(l, 40);

	printf("\nVazia:\n");
	int v2 = vazia(l);
	printf("%d", v2);

	printf("\nListando:\n");
	listar(l);

	printf("\nBuscando:\n");
	int b1 = buscar(l, 50);
	printf("%d\n", b1);

	printf("\nRemovendo:\n");
	int r1 = remover(l, 20);
	printf("%d", r1);

	printf("\nListando:\n");
	listar(l);

	printf("\n");
	return 0;
}

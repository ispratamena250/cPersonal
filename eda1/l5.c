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
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox)
		printf("%d ", novo->item);
}

int buscar(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox)
		if(novo->item == z) return 0;

	return 1;
}

int vazia(Lista* l){
	return (l->prim == NULL);
}

void libera(Lista* l){
	No* novo = l->prim;

	while(novo != NULL){
		No* aux = novo->prox;
		free(novo);
		novo = aux;
	}
}

int main(){
	Lista* l = cria();

	int v1 = vazia(l);
	printf("Vazia: %d", v1);

	insere(l, 10);
	insere(l, 20);
	insere(l, 30);

	printf("\nListando:\n");
	listar(l);

	printf("\nBusca:\n");
	int b1 = buscar(l, 10);
	int b2 = buscar(l, 20);
	printf("%d\n%d", b1, b2);

	printf("\nRemovendo:\n");
	int r1 = remover(l, 10);
	int r2 = remover(l, 100);
	printf("%d\n%d", r1, r2);

	printf("\nListando:\n");
	listar(l);

	int v2 = vazia(l);
	printf("\nVazia: %d", v2);

	libera(l);

	printf("\n");
	return 0;
}

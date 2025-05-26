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

int remover(Lista* l, int z){
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
			return 0;
		}
		ant = atual;
		atual = atual->prox;
	}

	return 1;
}

int vazia(Lista* l){
	if(l->prim == NULL){
		return 0;
	}
	return 1;
}

int pertence(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox){
		if(novo->item == z){
			return 0;
		}
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

int main(){
	Lista* l = cria();

	printf("\nVazia:\n");
	int v2 = vazia(l);
	printf("%d\n", v2);

	printf("\nInserindo:\n");
	insere(l, 10);
	insere(l, 20);
	insere(l, 30);
	insere(l, 40);

	printf("\nImprimindo:\n");
	imprime(l);

	printf("\nVazia:\n");
	int v1 = vazia(l);
	printf("%d\n", v1);

	printf("\nPertence:\n");
	int pert1 = pertence(l, 10);
	int pert2 = pertence(l, 60);
	printf("pert1: %d\npert2: %d\n", pert1, pert2);

	printf("\nRemove:\n");
	int r1 = remover(l, 30);
	int r2 = remover(l, 100);
	printf("r1: %d\nr2: %d\n", r1, r2);

	printf("\nImprimindo:\n");
	imprime(l);

	printf("\nVazia:\n");
	int v3 = vazia(l);
	printf("%d\n", v3);

	printf("\nLibera:\n");
	libera(l); 

	printf("\n");
	return 0;
}


















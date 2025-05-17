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

void listar(Lista* l){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox)
		printf("%d ", novo->item);
}

int buscar(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox)
		if(novo->item == z) return 1;

	return -1;
}

int main(){	
	Lista* l = cria();;

	insere(l, 90);
	insere(l, 100);
	insere(l, 200);

	printf("Percorre:\n");
	listar(l);

	printf("\nBusca:\n");
	int b1 = buscar(l, 90);
	int b2 = buscar(l, 100);
	printf("%d\n%d", b1, b2);

	printf("\n");
	return 0;
}

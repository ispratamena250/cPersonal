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

//Prototypes
Lista* cria();
void insere(Lista* l, int z);
void listar(Lista* l);
int buscar(Lista* l, int z);

int main(){
	Lista* l = cria();

	insere(l, 10);
	insere(l, 20);
	insere(l, 30);

	printf("Percorrendo:\n");
	listar(l);

	printf("\nBusca:\n");
	int b1 = buscar(l, 50);
	int b2 = buscar(l, 900);
	printf("%d\n%d", b1, b2);

	printf("\n");
	return 0;
}

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

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct no No;

struct lista{
	No* prim;
};

struct no{
	int z;
	No* prox;
};

//Prototypes
Lista* cria();
void insere(Lista* l, int z);
void listar(Lista* l);
int busca(Lista* l, int z);

int main(){
	Lista* l = cria();

	insere(l, 4);
	insere(l, 30);
	insere(l, 10);
	insere(l, 99);

	printf("Listando:\n");
	listar(l);

	printf("\nBuscando:\n");
	int b1 = busca(l, 4);
	int b2 = busca(l, 5);
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
	novo->z = z;
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
		printf("%d ", novo->z);
}

int busca(Lista* l, int z){
	for(No* novo=l->prim; novo!=NULL; novo=novo->prox)	
		if(novo->z == z) return 1;

	return -1;
}

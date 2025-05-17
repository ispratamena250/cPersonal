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
int busca(Lista* l, int z);
void percorre(Lista* l);

int main(){ //Isso, na verdade, e uma pilha
    Lista* l = cria();
    
    insere(l, 5);
    insere(l, 10);
    insere(l, 99);
    insere(l, 144);
    
    printf("Percorrendo:\n");
    percorre(l);
    
    printf("\nBuscando:\n");
    int b1 = busca(l, 99);
    int b2 = busca(l, 1000);
    printf("b1: %d\nb2: %d\n", b1, b2);
    
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
    novo->prox = l->prim;
    l->prim = novo;
}

int busca(Lista* l, int z){
    for(No* n=l->prim; n!=NULL; n=n->prox)
        if(n->item == z) return 1;
        
    return -1;
}

void percorre(Lista* l){
    for(No* n=l->prim; n!=NULL; n=n->prox)
        printf("%d ", n->item);
    
}

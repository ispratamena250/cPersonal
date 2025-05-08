#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    ListaNo* prim;
}Lista;

typedef struct listano{
    int item;
    ListaNo* prox;
}ListaNo;

//Prototypes
Lista* cria(void);
void insere(Lista* l, int v);
void imprime(Lista* l);
int percorre(Lista* l, int v);
void remove(Lista* l, int v);
int vazia(Lista* l);
void libera(Lista* l);

int main(){


    return 0;    
}

Lista* cria(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    //l.prim = NULL;
    l->prim = NULL;

    return l;
}

void insere(Lista* l, int v){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->item = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void imprime(Lista* l){
    for(ListaNo* p=l->prim; p!=NULL; p=p->prox)
        printf("Item = %d\n", p->item);

}

int percorre(Lista* l, int v){
    for(ListaNo* p=l->prim; p!=NULL; p=p->prox)
        if(p->item == v) return l;

    return 0;
}

void remove(Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;

    while(p != NULL && p->item != v){
        ant = p;
        p = p->prox;
    }

    if(p != NULL){
        if(ant == NULL)
            l->prim = p->prox;
        else   
            ant->prox = p->prox;

        free(p);
    }
}

int vazia(Lista* l){
    return (l->prim == NULL);
}

void libera(Lista* l){
    ListaNo* p = l->prim;

    while(p != NULL){
        ListaNo* t = p->prox;
        free(p);
        p = t;
    }

    free(l);
}
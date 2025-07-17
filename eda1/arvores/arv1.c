#include <stdio.h>
#include <stdlib.h>

typedef struct no ArvNo;
typedef struct arv Arv;

struct no
{
    int info;
    ArvNo *esq;
    ArvNo *dir;
};

struct arv
{
    ArvNo *raiz;
};

ArvNo *criaNo(int z, ArvNo *esq, ArvNo *dir)
{
    ArvNo *no = (ArvNo *)malloc(sizeof(ArvNo));
    no->info = z;
    no->esq = esq;
    no->dir = dir;

    return no;
}

Arv *criaArv(ArvNo *r)
{
    Arv *a = (Arv *)malloc(sizeof(Arv));
    a->raiz = r;

    return a;
}

void imprime(ArvNo *r)
{
    if (r != NULL)
    {
        printf("%d ", r->info); // pre ordem
        imprime(r->esq);
        imprime(r->dir);
    }
}

void imprimeRaiz(Arv *a)
{
    imprime(a->raiz);
}

void liberaNo(ArvNo *r)
{
    if (r != NULL)
    {
        liberaNo(r->esq);
        liberaNo(r->dir);
        free(r);
    }
}

void liberaArv(Arv *a)
{
    liberaNo(a->raiz);
    free(a);
}

ArvNo *buscaNo(ArvNo *r, int z)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (z == r->info)
    {
        return r;
    }
    else
    {
        ArvNo *no = buscaNo(r->esq, z);
        if (no != NULL)
        {
            return no;
        }
        else
        {
            return buscaNo(r->dir, z);
        }
    }
}

ArvNo *buscaArvore(Arv *a, int z)
{
    return buscaNo(a->raiz, z);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int altura(ArvNo *r)
{
    if (r == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(altura(r->esq), altura(r->dir));
    }
}

int alturaArv(Arv *a)
{
    return altura(a->raiz);
}

int main()
{
    Arv *a = criaArv(criaNo(50,
                            criaNo(10,
                                   criaNo(5, NULL, NULL),
                                   criaNo(30,
                                          criaNo(25, NULL, NULL),
                                              criaNo(45,
                                                     criaNo(40, NULL, NULL),
                                                     NULL))),
                            criaNo(99, NULL, NULL)));

    imprimeRaiz(a);

    return 0;
}
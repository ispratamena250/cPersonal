#ifndef LISTAHEADER_H
#define LISTAHEADER_H

typedef struct lista Lista;

Lista* cria();
void insere(Lista* l, int z);
int remover(Lista* l, int z);
void listar(Lista* l);
int buscar(Lista* l, int z);
int vazia(Lista* l);

#endif

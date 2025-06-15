#ifndef FILAHEADER_H
#define FILAHEADER_H

typedef struct fila Fila;

Fila* cria();
void insere(Fila* f, int z);
void remover(Fila* f, int z);
int vazia(Fila* f);
void imprimir(Fila* f);
int pertence(Fila* f, int z);

#endif

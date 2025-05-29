#ifndef FILAHEADER_H
#define FILAHEADER_H

typedef struct fila Fila;

Fila* cria();
void insere(Fila* f, int z);
int remover(Fila* f);
int vazia(Fila* f);
void listar(Fila* f);
int pertence(Fila* f, int z);

#endif

#ifndef FILAHEADER_H
#define FILAHEADER_H

typedef struct fila Fila;

Fila* criaFila();
void insereItemFila(Fila* f, int z);
int removerItemFila(Fila* f, int z);
int vaziaFila(Fila* f);
void imprimeFila(Fila* f);
int pertenceFila(Fila* f, int z);

#endif

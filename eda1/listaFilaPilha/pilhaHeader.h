#ifndef PILHAHEADER_H
#define PILHAHEADER_H

typedef struct pilha Pilha;

Pilha* cria();
void insere(Pilha* p, int z);
int remover(Pilha* p);
int vazia(Pilha* p);
int pertence(Pilha* p, int z);
void imprime(Pilha* p);

#endif

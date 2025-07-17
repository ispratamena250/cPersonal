#ifndef PILHAHEADER_H
#define PILHAHEADER_H

typedef struct pilha Pilha;

Pilha* criaPilha();
void insereItemPilha(Pilha* p, int z);
int removerItemPilha(Pilha* p, int z);
int vaziaPilha(Pilha* p);
int pertencePilha(Pilha* p, int z);
void imprimePilha(Pilha* p);

#endif

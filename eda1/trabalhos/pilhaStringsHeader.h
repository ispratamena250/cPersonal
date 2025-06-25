#ifndef PILHA_STRINGS_HEADER_H
#define PILHA_STRINGS_HEADER_H

typedef struct stack Stack;
typedef struct node Node;

Stack* createStack();
void insertItemStack(Stack* s, const char* c);
int removeItemStack(Stack* s);
int emptyStack(Stack* s);
int belongStack(Stack* s, const char* c);
void printStack(Stack* s);
void clearStack(Stack* s);
int stackSize(Stack* s);

#endif

/*
* Autor: Isaac Menezes Pereira, 190088885
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaStringsHeader.h"

typedef struct stack Stack;
typedef struct node Node;

struct stack{
	Node *top;
};

struct node{
	Node *next;
	char *item;
};

Stack *createStack(){
	Stack *s = (Stack*) malloc(sizeof(Stack));
	if(!s){
		perror("Fail to allocate memory for stack");
		exit(1);
	}

	s->top = NULL;

	return s;
}

void insertItemStack(Stack *s, const char *c){
	Node *new = (Node*) malloc(sizeof(Node));
	if(!new){
		perror("Fail to allocate memory for node");
		exit(1);
	}
	
	new->item = malloc(strlen(c)+1);
	if(!new->item){
		perror("Fail to allocate new item");	
		exit(1);
	}
	strcpy(new->item, c);

	new->next = s->top;
	s->top = new;
}

int removeItemStack(Stack *s){
	if(s->top == NULL)
		return 1;

	Node *actual = s->top;
	s->top = actual->next;

	free(actual->item);
	free(actual);

	return 0;
}

int emptyStack(Stack *s){
	if(s->top == NULL)
		return 1;

	return 0;
}

int belongStack(Stack *s, const char *c){
	for(Node *node=s->top; node!=NULL; node=node->next)
		if(strcmp(node->item, c) == 0)
			return 0;

	return 1;
}

void printStack(Stack *s){
	for(Node *node=s->top; node!=NULL; node=node->next)
		printf("%s\n", node->item);

}

void clearStack(Stack *s){
	while(!emptyStack(s))
		removeItemStack(s);

	free(s);
}

int stackSize(Stack *s){
	int count=0;

	for(Node *node=s->top; node!=NULL; node=node->next)
		count++;

	return count;
}

char *getStackItemAt(Stack *s, int index){
	if(index < 0)	
		return NULL;

	Node *node = s->top;
	int i=0;
	while(node != NULL){
		if(i == index)
			return node->item;

		node = node->next;
		i++;
	}

	return NULL;
}

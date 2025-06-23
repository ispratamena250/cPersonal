#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaStringsHeader.h"

typedef struct stack Stack;
typedef struct node Node;

struct stack{
	Node* top;
};

struct node{
	Node* next;
	char* item;
};

Stack* createStack(){
	Stack* s = (Stack*) malloc(sizeof(Stack));
	if(!s){
		perror("Fail to allocate memory for stack");
		exit(1);
	}

	s->top = NULL;

	return s;
}

void insertItemStack(Stack* s, const char* c){
	Node* new = (Node*) malloc(sizeof(Node));
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

int removeItemStack(Stack* s){
	if(s->top == NULL)
		return 1;

	Node* actual = s->top;
	s->top = actual->next;

	free(actual->item);
	free(actual);

	return 0;
}

int emptyStack(Stack* s){
	return (s->top == NULL);
}

int belongStack(Stack* s, const char* c){
	for(Node* node=s->top; node!=NULL; node=node->next)
		if(strcmp(node->item, c) == 0)
			return 0;

	return 1;
}

void printStack(Stack* s){
	for(Node* node=s->top; node!=NULL; node=node->next)
		printf("%s ", node->item);

	printf("\n");
}

void cleanStack(Stack *s){
	while(!emptyStack(s))
		removeItemStack(s);

	free(s);
}

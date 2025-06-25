#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaStringsHeader.h"

typedef struct queue Queue;
typedef struct node Node;

struct queue{
	Node* first;
	Node* end;
};

struct node{
	Node* next;
	char* item;
};

Queue* createQueue(){
	Queue* q = (Queue*) malloc(sizeof(Queue));
	if(!q){
		perror("Fail to allocate queue");
		exit(1);
	}
	q->first = NULL;
	q->end = NULL;

	return q;
}

void insertItemQueue(Queue* q, const char* c){
	Node* new = (Node*) malloc(sizeof(Node));
	if(!new){
		perror("Fail to allocate node");
		exit(1);
	}
	new->next = NULL;

	new->item = malloc(strlen(c) + 1);
	if(!new->item){
		perror("Fail to allocate string");
		exit(1);
	}
	strcpy(new->item, c);

	if(q->end != NULL)
		q->end->next = new;
	else
		q->first = new;

	q->end = new;
}

int removeItemQueue(Queue* q){
	if(q->first == NULL)
		return 1;

	Node* node = q->first;
	q->first = node->next;
	if(q->first == NULL)
		q->end = NULL;

	free(node->item);
	free(node);
	return 0;
}

int emptyQueue(Queue* q){
	if(q->first == NULL)
		return 0;

	return 1;
}

void printQueue(Queue* q){
	for(Node* node=q->first; node!=NULL; node=node->next)
		printf("%s ", node->item);

	printf("\n");
}

int belongQueue(Queue* q, const char* c){
	for(Node* node=q->first; node!=NULL; node=node->next)
		if(strcmp(node->item, c) == 0)
			return 0;

	return 1;
}

void clearQueue(Queue* q){
	while(!emptyQueue(q))
		removeItemQueue(q);

	free(q);
}

int queueSize(Queue* q){
	int count=0;

	for(Node* node=q->first; node!=NULL; node=node->next)
		count++;

	return count;
}

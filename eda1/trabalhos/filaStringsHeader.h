#ifndef FILA_STRING_HEADER_H
#define FILA_STRING_HEADER_H

typedef struct queue Queue;
typedef struct node Node;

Queue *createQueue();
void insertItemQueue(Queue *q, const char *c);
int removeItemQueue(Queue *q);
int emptyQueue(Queue *q);
void printQueue(Queue *q);
int belongQueue(Queue *q, const char *c);
void clearQueue(Queue *q);
int queueSize(Queue *q);

#endif

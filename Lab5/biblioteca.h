#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 100

typedef struct Element {
    char *val;
    struct Element *next;
} NodQ;

typedef struct {
    NodQ *front, *rear;
    int size;
} Queue;

typedef struct Elem {
    char val;
    struct Elem *next;
} NodS;

typedef struct {
    NodS *top;
} Stack;

Queue* create_queue();
void delete_queue(NodQ *front);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, char val[]);
NodQ dequeue(Queue *q);

Stack* create_stack();
void delete_stack(NodS *top);
int isEmptyStack(Stack *s);
void push(Stack *s, char val);
NodS pop(Stack *s);

#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
  int val;
  struct Elem *next;
} NodQ;

typedef struct {
  NodQ *front;
  NodQ *rear;
  int size;
} Queue;

Queue* create_queue();
void delete_queue(NodQ *front);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, int val);
NodQ dequeue(Queue *q);


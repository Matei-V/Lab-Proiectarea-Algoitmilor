typedef struct ElemQ {
  void *val;
  struct ElemQ *next;
} NodQ;

typedef struct {
  NodQ *front;
  NodQ *rear;
  int size;
} Queue;

Queue* create_queue();
void delete_queue(NodQ *front);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, void *val);
NodQ dequeue(Queue *q);


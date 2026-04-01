#include "queue.h"
#include "general.h"

Queue* create_queue(){
    Queue *q = malloc(sizeof(Queue));
    test_alocare(q);

    q->front=NULL;
    q->rear=NULL;
    q->size = 0;
    return q;
}

int isEmptyQueue(Queue *q) {
    if(q->rear == NULL)
        return 1;
    return 0;
}

void enqueue(Queue *q, void *val){
    NodQ *aux = malloc(sizeof(NodQ));
    test_alocare(aux);
    
    aux->val = val;

    if(isEmptyQueue(q)) {
        q->rear = aux;
        q->front = aux;
    }else {
        q->rear->next = aux;
        q->rear = aux;
    }
    q->size++;
}

NodQ dequeue(Queue *q) {
    if(isEmptyQueue(q))
        return (NodQ){0, NULL};

    NodQ* aux = q->front;

    NodQ ret;
    ret.val = aux->val;
    ret.next = 0;

    q->front = q->front->next;
    q->size--;

    free(aux);
    aux=NULL;

    if(q->front == NULL) q->rear = NULL;

    return ret;
}

void delete_queue(NodQ *front) {
    if(front == NULL)
        return;
    delete_queue(front->next);
    free(front);
    front=NULL;
}

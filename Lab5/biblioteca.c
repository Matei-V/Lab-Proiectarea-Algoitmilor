#include "biblioteca.h"

void test_alocare(void *p) {
    if(p == NULL) {
        printf("Alocare esuata");
        exit(1);
    }
}

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

void enqueue(Queue *q, char val[]){
    NodQ *aux = malloc(sizeof(NodQ));
    test_alocare(aux);
    aux->val = malloc(sizeof(char)*(strlen(val)+1));
    test_alocare(aux->val);
    strcpy(aux->val, val);
    aux->next=NULL;

    if(isEmptyQueue(q)) {
        (q)->rear = aux;
        (q)->front = aux;
    }else {
        q->rear->next = aux;
        q->rear = aux;
    }
    q->size++;
}

NodQ dequeue(Queue *q) {
    if(isEmptyQueue(q))
        return (NodQ){"", NULL};

    NodQ* aux = q->front;

    NodQ ret;
    strcpy(ret.val, aux->val);
    ret.next = 0;

    q->front = q->front->next;
    q->size--;

    free(aux->val);
    free(aux);
    aux=NULL;

    if(q->front == NULL) q->rear = NULL;

    return ret;
}

void delete_queue(NodQ *front) {
    if(front == NULL)
        return;
    delete_queue(front->next);
    free(front->val);
    free(front);
    front=NULL;
}

Stack* create_stack(){
    Stack *s = malloc(sizeof(Stack));
    test_alocare(s);

    s->top = NULL;

    return s;
}

int isEmptyStack(Stack *s) {
    if(s->top == NULL)
        return 1;
    return 0;
}

void push(Stack *s, char val){
    NodS *aux = malloc(sizeof(NodS));
    aux->val = val;
    aux->next=s->top;
    s->top = aux;
    
}

NodS pop(Stack *s) {
    if(isEmptyStack(s))
        return (NodS){'\0', NULL};

    NodS* aux = s->top;

    NodS ret;
    ret.val = aux->val;
    ret.next = NULL;

    s->top = s->top->next;

    free(aux);
    aux=NULL;

    return ret;
}

void delete_stack(NodS *top) {
    if(top == NULL)
        return;
    delete_stack(top->next);
    free(top);
    top=NULL;
}

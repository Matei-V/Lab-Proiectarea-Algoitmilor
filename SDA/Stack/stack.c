#include "stack.h"

void test_alocare(void *p) {
    if(p == NULL) {
        printf("Alocare esuata");
        exit(1);
    }
}

Stack* create_stack(){
    Stack *s = malloc(sizeof(Stack));
    test_alocare(s);

    s->top = NULL;
    s->size = 0;
    return s;
}

int isEmptyStack(Stack *s) {
    if(s->top == NULL)
        return 1;
    return 0;
}


void push(Stack *s, int val){
    NodS *aux = malloc(sizeof(NodS));
    aux->val = val;
    aux->next=s->top;
    s->top = aux;
    s->size++;
}

NodS pop(Stack *s) {
    if(isEmptyStack(s))
        return (NodS){0, NULL};

    NodS* aux = s->top;

    NodS ret;
    ret.val = aux->val;
    ret.next = NULL;

    s->top = s->top->next;

    free(aux);
    aux=NULL;
    s->size--;
    return ret;
}

void delete_stack(NodS *top) {
    if(top == NULL)
        return;
    delete_stack(top->next);
    free(top);
    top=NULL;
}

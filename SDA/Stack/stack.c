#include "stack.h"

void test_alocare(void *p) {
    if(p == NULL) {
        printf("Alocare esuata");
        exit(1);
    }
}

void push(Stack *s, int val){
    NodS *aux = malloc(sizeof(NodS));
    aux->val = val;
    aux->next=s->top;
    s->top = aux;
    
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

    return ret;
}

void delete_stack(NodS *top) {
    if(top == NULL)
        return;
    delete_stack(top->next);
    free(top);
    top=NULL;
}

#include "biblioteca.h"

int main() {
    Queue *q = create_queue();
    Stack *s = create_stack();

    char val[CMAX];
    while(strcmp(val, "stop") != 0) {
        scanf("%s", val);
        if(strcmp(val, "stop") != 0) enqueue(q, val);
    }

    for(int i = 0 ; i < q->size; i++) {
        NodQ aux = dequeue(q);
        for(int i = 0; aux.val[i] != '\0'; i++) {
            push(s, aux.val[i]);
        }
        int i = 0;        
        while(!isEmptyStack(s)) {
            NodS top = pop(s);
            aux.val[i++] = top.val;
        }
        enqueue(q, aux.val);
    }

    while(!isEmptyQueue(q)) {
        NodQ aux = dequeue(q);
        printf("%s ", aux.val);
    }

    delete_stack(s->top);
    delete_queue(q->front);
    return 0;
}

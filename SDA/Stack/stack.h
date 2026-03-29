#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int val;
    struct Elem *next;
} NodS;

typedef struct {
    NodS *top;
} Stack;

Stack* create_stack();
void delete_stack(NodS *top);
int isEmptyStack(Stack *s);
void push(Stack *s, int val);
NodS pop(Stack *s);

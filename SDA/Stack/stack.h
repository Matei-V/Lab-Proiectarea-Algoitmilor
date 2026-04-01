#include <stdio.h>
#include <stdlib.h>

typedef struct ElemS {
    int val;
    struct ElemS *next;
} NodS;

typedef struct {
    NodS *top;
    int size;
} Stack;

Stack* create_stack();
void delete_stack(NodS *top);
int isEmptyStack(Stack *s);
void push(Stack *s, int val);
NodS pop(Stack *s);

#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int tip_drone;
    struct Elem *next;
} Drona;

void init_lista(Drona **head);
void gasire_sablon(Drona *head, int sablon_st[], int size_st, int sablon_fn[], int size_fn, int **idx, int *size_idx);
void elim_sablon(Drona *head, int *idx, int size_idx);
void afisare_lista(Drona *head);
void dealocare_lista(Drona *head);
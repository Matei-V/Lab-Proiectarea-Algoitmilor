#include "drone.h"
#include <stdlib.h>


int main() {
    Drona *head;
    int sablon_st[] = {7}, sablon_fn[] = {9, 3};
    init_lista(&head);

    int *idx = malloc(sizeof(int)), size_idx;
    gasire_sablon(head, sablon_st, sizeof(sablon_st)/sizeof(int), sablon_fn, sizeof(sablon_fn)/sizeof(int), &idx, &size_idx);
    elim_sablon(head, idx, size_idx);

    for(int i = 0; i < size_idx; i++) {
        printf("%d", idx[i]);
    }

    afisare_lista(head);
    dealocare_lista(head);
    return 0;
}

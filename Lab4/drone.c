#include "drone.h"
#include <stdlib.h>

void init_lista(Drona **head) {
    Drona *santinela = malloc(sizeof(Drona));
    *head = santinela;

    int n, tip_drona;
    Drona *p;
    p = *head;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tip_drona);
        Drona *aux = malloc(sizeof(Drona));
        aux->tip_drone = tip_drona;
        p->next = aux;
        p = aux;
    }
}

void dealocare_lista(Drona *head) {
    if(head->next != NULL) dealocare_lista(head->next);

    free(head);
    head=NULL;

}

void gasire_sablon(Drona *head, int sablon_st[], int size_st, int sablon_fn[], int size_fn, int **idx, int *size_idx) {
    int idx_st = 0, cur_st = 0, idx_fn = 0, cur_fn = 0, cur_idx = 0;
    Drona *it = head->next;
    for(;it != NULL;) {
       if(it->tip_drone == sablon_st[cur_st]) {
            idx_st = cur_idx;
        }else {
            it=it->next;
            continue;
        }
        while(it->tip_drone == sablon_st[cur_st] && it != NULL && cur_st < size_st) {
            cur_st++;
            it=it->next;
            cur_idx++;
        }
        
        if(cur_st == size_st) {
            while(it->tip_drone != sablon_fn[cur_fn] && it->next != NULL) {
                it = it->next;
                cur_idx++;
            }
            if(it->tip_drone == sablon_fn[cur_fn]) {
                idx_fn = cur_idx;
            }
            while(it->tip_drone == sablon_fn[cur_fn] && it->next != NULL && cur_fn < size_fn) {
                cur_fn++;
                it=it->next;
                cur_idx++;
            }
            if(cur_fn == size_fn) {
                *idx = realloc(*idx, *size_idx + 2);
                (*idx)[*size_idx] = idx_st;
                (*idx)[*size_idx + 1] = idx_fn+cur_fn-1;
                (*size_idx) += 2;
            }
        }

        cur_st = 0, cur_fn = 0;
    }
}

void afisare_lista(Drona *head) {
    Drona *it = head->next;

    for(; it != NULL; it=it->next) {
        printf("%d\n", it->tip_drone);
    }

}

void elim_sablon(Drona *head, int *idx, int size_idx) {
    for(int i = size_idx-1; i > 0; i-=2) {
        Drona *it = head;
        for(int j = 0; j < idx[i-1]; j++, it=it->next);
        Drona *st = it;
        for(int j = 0; j < idx[i]-1; j++){
            it=it->next;
        }
        Drona *fn = it;
        Drona *aux = st->next;
        st->next = fn->next;
        fn->next = NULL;
        dealocare_lista(aux);
    }

}




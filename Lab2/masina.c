#include "masina.h"
#include <stdlib.h>
#include <string.h>

void check_alloc(void *p) {
    if(p == NULL) {
        printf("Alocarea dinamica a esuat");
        exit(1);
    }

}

void citire(struct Masina *m) {
    FILE* f = fopen("date.in", "r");

    (*m).marca = malloc(100*sizeof(char));
    //printf("Marca: ");
    //scanf("%s", (*m).marca);
    fscanf(f, "%s", (*m).marca);

    int dim = strlen((*m).marca);
    (*m).marca = realloc((*m).marca, (dim+1)*sizeof(char));
    check_alloc((*m).marca);

    //printf("Pret: ");
    //scanf("%d", &(*m).pret);
    fscanf(f, "%d", &(*m).pret);

    //printf("Numar: ");
    //scanf("%s", m->numar);
    fscanf(f,"%s", m->numar);

}

void alocare(struct Masina **m, int n) {
    (*m) = malloc(n*sizeof(struct Masina));
    check_alloc(*m);
    for(int i = 0; i < n; i++) {
        citire(*(m)+i);
    }
}

void afisare(struct Masina *m) {
    printf("Marca: %s \nPretul:%d \n Numar: %s\n", m->marca, m->pret, m->numar);
}

void setare_marca(struct Masina *m, char *marca_nou) {
    m->marca = realloc(m->marca, strlen(marca_nou)+1);
    strcpy(m->marca, marca_nou);
}

void copiere(struct Masina *dest, struct Masina *src) {
    dest->marca = malloc((strlen(src->marca)+1)*sizeof(char));
    strcpy(dest->marca, src->marca);
    dest->pret = src->pret;
    strcpy(dest->numar, src->numar);
}
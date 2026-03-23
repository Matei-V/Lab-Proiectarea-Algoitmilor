#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Masina {
char *marca;
int pret;
char numar[8];
};

void citire(struct Masina* m);
void alocare(struct Masina** m, int n);
void afisare(struct Masina* m);
void setare_marca(struct Masina* m, char* marca_nou);
void copiere(struct Masina* dest, struct Masina* src);
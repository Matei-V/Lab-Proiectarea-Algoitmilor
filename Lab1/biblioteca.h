#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *generare_vector(int dim, int k, float d);
void afisare_vector(int *v, int dim);
void calcul_histograma(int *v, int dim, int k, int **h);
int *calcul_histograma_bin(int *h, int k, int N);
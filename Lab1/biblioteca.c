#include "biblioteca.h"

void verificare_alocare(void *p) {
    if (p == NULL) {
        printf("Eroare alocarea dinamica\n");
        exit(1);
    }
}

int *generare_vector(int dim, int k, float d) {
    int *v = (int *)malloc(dim * sizeof(int));
    verificare_alocare(v);
    int i = 0;
    d = d/100;
    srand(time(NULL));

    for(i = 0; i < dim && i < (d)*dim; i++) {
        int x = rand()%k;
        int x_n = (2*k)*x/k - k;

        v[i] = x_n;
    }

    return v;
}

void afisare_vector(int *v, int dim) {
    for(int i = 0; i < dim; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void calcul_histograma(int *v, int dim, int k, int **h) {
    *h = (int *)calloc(2 * k + 1, sizeof(int));
    verificare_alocare(*h);
    for(int i = 0; i < dim; i++) {
            (*h)[v[i] + k]++;
    }
}

int *calcul_histograma_bin(int *h, int k, int N) {
    int size_bin = 2 * k / N;
    int rest = (2 * k) % N;
    int *h_bin = (int *)calloc(N + 1, sizeof(int));
    verificare_alocare(h_bin);

    int s = 0;
    int j = 0;
    for(int i = 0; i < 2 * k; i++) {
        s += h[i];
        if(i % size_bin == size_bin - 1) {
            h_bin[j] = s;
            s = 0;
            j++;
        }
    }

    h_bin[N-1] += s;
    
    return h_bin;
}
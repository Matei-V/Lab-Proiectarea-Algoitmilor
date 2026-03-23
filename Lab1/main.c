#include "biblioteca.h"

int main() {
    int dim = 10, k = 5, d = 70;
    int N;

    int *v = generare_vector(dim, k, d);
    int *h = NULL;
    afisare_vector(v, dim);
    printf("\n");
    calcul_histograma(v, dim, k, &h);

    scanf("%d", &N);
    int *h_bin = calcul_histograma_bin(h, k, N);

    int rest = (2 * k) % N;
    for(int i = 0; i < N - 1; i++) {
        printf("[%d, %d): ", i * (2 * k / N)-k, (i + 1) * (2 * k / N) - k);
        for(int j = 0; j < h_bin[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    
    printf("[%d, %d]: ", (N-1) * (2 * k / N)-k, k);
    for(int j = 0; j < h_bin[N-1]; j++) {
        printf("*");
    }
    printf("\n");
    

    free(v);
    v = NULL;
    free(h);
    h = NULL;
    free(h_bin);
    h_bin = NULL;


    return 0;
}

#include "biblioteca.h"

int main() {
    int n = 7;
    float *v = initiere(n);

    int *a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        a[i] = (float)v[i];
    }
    counting_sort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", *(a+i));
    }

    quick_sort(v, 0, n-1);
    afisare(v, n);

    
    
    printf("\n");
    free(v);
    v = NULL;
    free(a);
    a = NULL;
    return 0;
}

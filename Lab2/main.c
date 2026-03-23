#include "masina.h"

int main() {
    int n;
    scanf("%d", &n);

    struct Masina** m = malloc(n*sizeof(struct Masina*));

    for(int i = 0; i < n; i++) {
        alocare(&(*(m + i)), n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            afisare(*(m + i) + j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){ 
            free((*(m+i)+j)->marca);
            (*(m+i)+j)->marca = NULL;
        }
        free(*(m+i));
        *(m+i) = NULL;
    }
    free(m);
    m = NULL;
    
    return 0;
}

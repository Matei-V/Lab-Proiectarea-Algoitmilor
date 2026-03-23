#include "biblioteca.h"

void verificare_alocare(void* p) {
    if (p == NULL) {
        printf("Eroare la alocare!\n");
        exit(1);
    }
}

float* initiere(int n) {
    float* v = malloc(n*sizeof(float));
    verificare_alocare(v);
    citire(v, n);
    return v;
}

void citire(float *v, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%f", v+i);
    }
}

void afisare(float *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%.2f ", *(v+i));
    }
    printf("\n");
}

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int mediana(float *v, int a, int b, int c) {
    if((v[a] < v[b] && v[b] < v[c]) || (v[c] < v[b] && v[b] < v[a])) return b;
    if((v[b] < v[a] && v[b] < v[c]) || (v[c] < v[b] && v[a] < v[b])) return a;
    return c;
}

int part(float *v, int l, int h) {
    int m = (l + h)/2;
    int q = mediana(v, l, m, h);
    swap(v + q, v + h);
    float pivot = v[h];
    int i = l - 1;
    for(int j = l; j < h; j++) {
        if(v[j] > pivot) {
            i++;
            swap(v+i, v+j);
        }
    }
    swap(v+i+1, v+h);
    q = i + 1;
    return q;
}

void quick_sort(float *v, int l, int h) {
    if(l < h) {
        int q = part(v, l, h);
        quick_sort(v, l, q - 1);
        quick_sort(v, q + 1, h);
    }
}

void counting_sort(int *v, int n) {
    int kmax =  -1;
    for(int i = 0; i < n; i++) {
        if(v[i] > kmax) {
            kmax = v[i];
        }
    }

    int *vf = malloc((kmax+1)*sizeof(int));
    int *vaux = malloc((kmax+1)*sizeof(int));

    for(int i = 0; i < kmax+1; i++) {
        vf[v[i]]++;
    }

    for(int i = 1; i < kmax+1; i++) {
        vaux[i] = vf[i] + vaux[i-1];
    }

    int *vs = (int *)malloc((n)*sizeof(int));
    for(int i = 0; i < n; i++) {
        vs[i]=-1;
    }

    for(int i = 0; i < n; i++) {
        vs[vaux[v[i]]-1] = v[i];
        vaux[v[i]]--;
    }  

    for(int i = 0; i < n; i++) {
        printf("%d ", *(vs+i));
    }
    printf("\n");
    free(vf);
    vf = NULL;
    free(vaux);
    vaux = NULL;
    free(vs);
    vs = NULL;

}

//3 55 17 8 98 61 24
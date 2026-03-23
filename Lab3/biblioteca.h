#include <stdio.h>
#include <stdlib.h>

#define KMAX 100

float* initiere(int n);
void citire(float* v, int n);
void afisare(float* v, int n);
void quick_sort(float* v, int l, int h);
void counting_sort(int* v, int n);
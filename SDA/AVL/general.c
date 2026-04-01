#include "general.h"

void test_alocare(void *p) {
  if(p == NULL){
    printf("Alocare esuata");
    exit(1);
  }
}

int max(int a, int b) {
  return a < b ? b : a;
}

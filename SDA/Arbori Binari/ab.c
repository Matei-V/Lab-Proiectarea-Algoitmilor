#include "ab.h"
#include "queue.h"
#include "general.h"


NodAB* Create(int n) {
  int val;
  if(n > 0) {
    NodAB* root= malloc(sizeof(NodAB));
    printf("Valoare nod"); scanf("%d", &val);
    (root->val)= val;
    root->left = Create(n/2);
    root->right = Create(n-1-n/2);
    return root; 
  }
  return NULL;
}
NodAB* CreatePreorder(){
  int val;
  char c;
  NodAB* root= malloc(sizeof(NodAB));
  printf("Dati valoarea pentru nod: "); scanf("%d", &val);
  root->val =val;
  printf("Nodul adaugat are subarbore stang? d/n "); scanf("%c", &c);
  if (c=='d') root->left = CreatePreorder();
  else root->left=NULL;
printf("Nodul adaugat are subarbore drept? d/n " ); scanf("%c", &c);
  if (c=='d') root->right= CreatePreorder();
  else root->right=NULL;
  return root;
} 

NodAB* newNode(int val) {
  NodAB *nod = malloc(sizeof(NodAB));
  test_alocare(nod);
  nod->val = val;
  nod->left = nod->right = NULL;
  return nod;
}

int isEmptyAB(AB tree) {
  return tree.root == NULL;
}
int isInterior(NodAB *nod) {
  if (nod == NULL) return -1;
  return ( nod->left != NULL || nod->right != NULL);
}
int isLeaf(NodAB *nod) {
  if (nod == NULL) return -1;
  return !isInterior(nod);
}

NodAB* minValue(NodAB *nod){
  if (nod == NULL) return NULL;
  while (nod->left != NULL)
    nod = nod->left;
  return nod;
}

NodAB* maxValue(NodAB *nod){
  if (nod == NULL) return NULL;
  while (nod->right != NULL)
    nod = nod->right;
  return nod;
}

NodAB* findKthElement(NodAB *nod, int k) {
  static int count = 0;  

  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->left != NULL) {
    NodAB *aux = findKthElement(nod->left, k); 
    if(aux != NULL)
      return aux;
  }
  count++;  
  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->right != NULL) {
    NodAB *aux = findKthElement(nod->right, k);
    if(aux != NULL)
      return aux;
  }
  return NULL;
}

void Preorder(NodAB *nod) {
  if(nod != NULL) {
    printf("%d", nod->val);
    Preorder(nod->left);
    Preorder(nod->right);
  }
}

void freeNode(NodAB **nod) {
  free(*nod);
  *nod = NULL;
}

void deleteDeepest(AB tree, NodAB *d_nod) {
  Queue *Q = create_queue();
  NodAB *p = tree.root;
  enqueue(Q, tree.root);

  while (!isEmptyQueue(Q)) {
    NodQ top = dequeue(Q);
    NodAB *current = (NodAB*)top.val;

   if(current->right != NULL) {
      if(current->right == d_nod) {
        current->right = NULL;
        freeNode(&d_nod);
        return;
      }
    } else enqueue(Q, (void*)current->right);
    if(current->left != NULL) {
      if(current->left == d_nod) {
        current->left = NULL;
        freeNode(&d_nod);
        return;
      } else enqueue(Q, (void*)current->left);
    }
  }
}

void deleteByKey(AB tree, int key) {
  Queue *Q = create_queue();
  enqueue(Q, tree.root);
  NodAB *current, *key_nod;
  while (!isEmptyQueue(Q)) {
    NodQ top = dequeue(Q);
    current = (NodAB*)top.val;
    if(current->val == key) key_nod = current;
    if(current->right != NULL)  enqueue(Q, current->right);
    if(current->left != NULL)  enqueue(Q, current->left);
  }
  if(key_nod == NULL) return;

  if(tree.root->val == key && tree.root->left == NULL && tree.root->right == NULL) {
    freeNode(&tree.root);
  } else {
    int aux = current->val;
    deleteDeepest(tree, current);
    key_nod->val = aux;
  }
}

int Height(NodAB *nod) {
  if(nod == NULL) return -1;

  int hl = Height(nod->left);
  int hs = Height(nod->right);
  return 1+(hs > hl ? hs : hl);
}

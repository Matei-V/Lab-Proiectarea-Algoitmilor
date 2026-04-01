#include "avl.h"
#include "general.h"


NodAVL* RightRotation(NodAVL *z) { 
  NodAVL *y = z->left;
  NodAVL *T3 = y->right;

  y->right = z;
  z->left = T3;

  z->height = max(Height(z->left), Height(z->right))+1;
  y->height = max(Height(y->left), Height(y->right))+1;
  return y;
}

NodAVL* LeftRotation(NodAVL *z) {
  NodAVL *y = z->right;
  NodAVL *T2 = y->left;
  y->left = z;
  z->right = T2;
  z->height = max(Height(z->left), Height(z->right))+1;
  y->height = max(Height(y->left), Height(y->right))+1;
  return y;
}

NodAVL* LRRotation(NodAVL *z) {
  z->left = LeftRotation(z->left);
  return RightRotation(z);
}

NodAVL* RLRotation(NodAVL *z) {
  z->right = RightRotation(z->right);
  return LeftRotation(z);
}

NodAVL* newNode(int val) {
  NodAVL *nod = malloc(sizeof(NodAVL));
  test_alocare(nod);
  nod->val = val;
  nod->left = nod->right = NULL;
  nod->height = 0;
  return nod;
}

NodAVL* insert(NodAVL* nod, int key) {
  if (nod == NULL) return newNode(key); 
  if (key < nod->val) nod->left = insert(nod->left, key); 
  else if (key > nod->val) nod->right = insert(nod->right, key);
  else return nod;

  nod->height = 1 + max(Height(nod->left), Height(nod->right));
  int k = (Height(nod->left) - Height(nod->right));
// LL Case
  if (k > 1 && key < nod->left->val)
    return RightRotation(nod); 
// RR Case
  if (k < -1 && key > nod->right->val)
    return LeftRotation(nod);
//LR Case
  if (k > 1 && nod->left!=NULL && key > nod->left->val) 
    return LRRotation(nod); 
// RL Case
  if (k < -1 && nod->right!=NULL && key < nod->right->val)
    return RLRotation(nod);

  return nod; 
}

void freeNode(NodAVL **nod) {
  free(*nod);
  *nod = NULL;
}

NodAVL* deleteNod(NodAVL* nod, int key) { 
  if (nod == NULL) return nod;
  if (key < nod->val) nod->left = deleteNod(nod->left, key);
  else if (key > nod->val) nod->right = deleteNod(nod->right, key);
  else {
    if (nod->left == NULL) {
      NodAVL *current = nod;
      nod=nod->right; 
      freeNode(&current); 
    return nod;
    } else if (nod->right == NULL){
      NodAVL *current = nod;
      nod=nod->left;
      freeNode(&current);
      return nod;
    }
    NodAVL* current = minValue(nod->right);
    nod->val = current->val;
    nod->right = deleteNod(nod->right, current->val);
  }
  return nod;
}

int isEmptyAVL(AVL tree) {
  return tree.root == NULL;
}
int isInterior(NodAVL *nod) {
  if (nod == NULL) return -1;
  return ( nod->left != NULL || nod->right != NULL);
}
int isLeaf(NodAVL *nod) {
  if (nod == NULL) return -1;
  return !isInterior(nod);
}

NodAVL* minValue(NodAVL *nod){
  if (nod == NULL) return NULL;
  while (nod->left != NULL)
    nod = nod->left;
  return nod;
}

NodAVL* maxValue(NodAVL *nod){
  if (nod == NULL) return NULL;
  while (nod->right != NULL)
    nod = nod->right;
  return nod;
}

NodAVL* findKthElement(NodAVL *nod, int k) {
  static int count = 0;  

  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->left != NULL) {
    NodAVL *aux = findKthElement(nod->left, k); 
    if(aux != NULL)
      return aux;
  }
  count++;  
  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->right != NULL) {
    NodAVL *aux = findKthElement(nod->right, k);
    if(aux != NULL)
      return aux;
  }
  return NULL;
}

NodAVL* search(NodAVL *nod, int key) {
  if(nod->val == key) 
    return nod;
  if(nod->val > key) return search(nod->left, key);
  if(nod->val < key) return search(nod->right, key);
  return NULL;
}

NodAVL* Predecesor(NodAVL* nod, int k) { 
  NodAVL* pred = NULL; 
  while (nod != NULL) {
    if (nod->val < k) { 
      pred = nod; 
      nod = nod->right; 
    } else if (nod->val > k) { 
      nod = nod->left; 
    } else { 
      if (nod->left != NULL) { 
        return maxValue(nod->left);
      }
      break;
    }
  }
  return pred;
}

int Height(NodAVL *nod) {
  if(nod == NULL) return -1;
  return nod->height;
}

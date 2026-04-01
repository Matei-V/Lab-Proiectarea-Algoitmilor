#include "bst.h"
#include "general.h"


NodBST* newNode(int val) {
  NodBST *nod = malloc(sizeof(NodBST));
  test_alocare(nod);
  nod->val = val;
  nod->left = nod->right = NULL;
  return nod;
}
NodBST* insert(NodBST* nod, int key) {
  if (nod == NULL) return newNode(key); 
  if (key < nod->val) nod->left = insert(nod->left, key); 
  if (key > nod->val) nod->right = insert(nod->right, key); 

  return nod; 
}

void freeNode(NodBST **nod) {
  free(*nod);
  *nod = NULL;
}

NodBST* deleteNod(NodBST* nod, int key) { 
  if (nod == NULL) return nod;
  if (key < nod->val) nod->left = deleteNod(nod->left, key);
  else if (key > nod->val) nod->right = deleteNod(nod->right, key);
  else {
    if (nod->left == NULL) {
      NodBST *current = nod;
      nod=nod->right; 
      freeNode(&current); 
    return nod;
    } else if (nod->right == NULL){
      NodBST *current = nod;
      nod=nod->left;
      freeNode(&current);
      return nod;
    }
    NodBST* current = minValue(nod->right);
    nod->val = current->val;
    nod->right = deleteNod(nod->right, current->val);
  }
  return nod;
}

int isEmptyBST(BST tree) {
  return tree.root == NULL;
}
int isInterior(NodBST *nod) {
  if (nod == NULL) return -1;
  return ( nod->left != NULL || nod->right != NULL);
}
int isLeaf(NodBST *nod) {
  if (nod == NULL) return -1;
  return !isInterior(nod);
}

NodBST* minValue(NodBST *nod){
  if (nod == NULL) return NULL;
  while (nod->left != NULL)
    nod = nod->left;
  return nod;
}

NodBST* maxValue(NodBST *nod){
  if (nod == NULL) return NULL;
  while (nod->right != NULL)
    nod = nod->right;
  return nod;
}

NodBST* findKthElement(NodBST *nod, int k) {
  static int count = 0;  

  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->left != NULL) {
    NodBST *aux = findKthElement(nod->left, k); 
    if(aux != NULL)
      return aux;
  }
  count++;  
  if(count == k) {
    count = 0;
    return nod;
  }

  if(nod->right != NULL) {
    NodBST *aux = findKthElement(nod->right, k);
    if(aux != NULL)
      return aux;
  }
  return NULL;
}

NodBST* search(NodBST *nod, int key) {
  if(nod->val == key) 
    return nod;
  if(nod->val > key) return search(nod->left, key);
  if(nod->val < key) return search(nod->right, key);
  return NULL;
}

NodBST* Predecesor(NodBST* nod, int k) { 
  NodBST* pred = NULL; 
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

int Height(NodBST *nod) {
  if(nod == NULL) return -1;

  int hl = Height(nod->left);
  int hs = Height(nod->right);
  return 1+(hs > hl ? hs : hl);
}

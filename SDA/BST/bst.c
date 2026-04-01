#include "bst.h"
#include "queue.h"
#include "general.h"


NodBST* Create(int n) {
  int val;
  if(n > 0) {
    NodBST* root= malloc(sizeof(NodBST));
    printf("Valoare nod"); scanf("%d", &val);
    (root->val)= val;
    root->left = Create(n/2);
    root->right = Create(n-1-n/2);
    return root; 
  }
  return NULL;
}


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

void Preorder(NodBST *nod) {
  if(nod != NULL) {
    printf("%d", nod->val);
    Preorder(nod->left);
    Preorder(nod->right);
  }
}

void freeNode(NodBST **nod) {
  free(*nod);
  *nod = NULL;
}

void deleteDeepest(BST tree, NodBST *d_nod) {
  Queue *Q = create_queue();
  NodBST *p = tree.root;
  enqueue(Q, tree.root);

  while (!isEmptyQueue(Q)) {
    NodQ top = dequeue(Q);
    NodBST *current = (NodBST*)top.val;

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

void deleteByKey(BST tree, int key) {
  Queue *Q = create_queue();
  enqueue(Q, tree.root);
  NodBST *current, *key_nod;
  while (!isEmptyQueue(Q)) {
    NodQ top = dequeue(Q);
    current = (NodBST*)top.val;
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

int Height(NodBST *nod) {
  if(nod == NULL) return -1;

  int hl = Height(nod->left);
  int hs = Height(nod->right);
  return 1+(hs > hl ? hs : hl);
}

typedef struct ElemBST {
  int val;
  struct ElemBST *left, *right;
} NodBST;

typedef struct {
  NodBST *root;
} BST;

NodBST* Create(int n);

int isEmpty(BST tree);
int isInterior(NodBST *nod);
int isLeaf(NodBST *nod);

NodBST* newNode(int val);
NodBST* insert(NodBST* root, int key);
NodBST* minValue(NodBST *root);
NodBST* findKthElement(NodBST *root, int k);
NodBST* search(NodBST *root, int key);
NodBST* Predecesor(NodBST* nod, int k);

void deleteByKey(BST tree, int key);

int Height(NodBST *nod);

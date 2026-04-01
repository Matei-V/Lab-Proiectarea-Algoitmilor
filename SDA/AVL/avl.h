typedef struct ElemAVL {
  int val;
  int height;
  struct ElemAVL *left, *right;
} NodAVL;

typedef struct {
  NodAVL *root;
} AVL;

NodAVL* Create(int n);

int isEmpty(AVL tree);
int isInterior(NodAVL *nod);
int isLeaf(NodAVL *nod);

NodAVL* newNode(int val);
NodAVL* insert(NodAVL* root, int key);
NodAVL* minValue(NodAVL *root);
NodAVL* findKthElement(NodAVL *root, int k);
NodAVL* search(NodAVL *root, int key);
NodAVL* Predecesor(NodAVL* nod, int k);

void deleteByKey(AVL tree, int key);

int Height(NodAVL *nod);

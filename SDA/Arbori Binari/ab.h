typedef struct ElemAB {
  int val;
  struct ElemAB *left, *right;
} NodAB;

typedef struct {
  NodAB *root;
} AB;

NodAB* Create(int n);

int isEmpty(AB tree);
int isInterior(NodAB *nod);
int isLeaf(NodAB *nod);

NodAB* newNode(int val);
NodAB* insert(NodAB* root, int key);
NodAB* minValue(NodAB *root);
NodAB* findKthElement(NodAB *root, int k);
NodAB* search(NodAB *root, int key);
NodAB* CreatePreorder();

void Preorder(NodAB *nod);
void deleteByKey(AB tree, int key);

int Height(NodAB *nod);

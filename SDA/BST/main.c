#include "bst.h"
#include "general.h"

int main(){
  BST tree;
  tree.root = insert(tree.root, 7);
  tree.root = insert(tree.root, 4);
  tree.root = insert(tree.root, 9);
  tree.root = insert(tree.root, 2);
  tree.root = insert(tree.root, 5);
  
  NodBST *min = findKthElement(tree.root, 4);
  printf("%d\n", min->val);
  deleteByKey(tree, min->val);
  min = findKthElement(tree.root, 4);
  printf("%d", min->val);
  return 0;
}

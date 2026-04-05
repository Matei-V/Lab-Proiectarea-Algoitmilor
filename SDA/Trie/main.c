#include "general.h"
#include "trie.h"

int main() {
  Trie t = Create();

  t.root = insert(t.root, "carte");
  t.root = insert(t.root, "pensula");
  t.root = insert(t.root, "penar");
  t.root = insert(t.root, "carot");
  t.root = insert(t.root, "cisterna");
  int r = Cautare(t.root, "penaru");
  printf("%d", r);
  return 0;
}

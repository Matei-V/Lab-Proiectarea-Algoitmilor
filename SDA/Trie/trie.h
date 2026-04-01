typedef struct ElemTrie {
  int final;
  struct ElemTrie *next[26];
} NodTrie;

typedef struct {
  NodTrie *root;
} Trie;

Trie Create();
void Delete(Trie t);

NodTrie* insert(NodTrie *nod, char *c);

int Cautare(NodTrie *nod, char *c);
void afisarePrefix(NodTrie *nod, char *pref);


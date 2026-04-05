#include "general.h"
#include "trie.h"

Trie Create() {
  NodTrie *root = malloc(sizeof(NodTrie));
  root->final = 0;
  for(int i = 0; i < 26; i++) root->next[i] = NULL;
  Trie ret;
  ret.root = root;
  return ret;
}

NodTrie* newNode() {
  NodTrie *nod = malloc(sizeof(NodTrie));
  nod->final = 0;
  for(int i = 0; i < 26; i++) nod->next[i] = NULL;
  return nod;
}

NodTrie* insert(NodTrie *nod, char *c) {
  if(*(c+1) == '\0') {
    nod = newNode();
    nod->final = 1;
    return nod;
  }
  
  if(nod == NULL) {
    nod = newNode();
    nod->next[*c - 'a'] = insert(nod->next[*c - 'a'], c + 1);
    return nod;
  }

  nod->next[*c - 'a'] = insert(nod->next[*c - 'a'], c + 1);

  return nod;
}

int Cautare(NodTrie *nod, char *c) {
  if(*c == '\0') return 1;
  if(nod->next[*c - 'a'] != NULL)
    return Cautare(nod->next[*c - 'a'], c + 1);
  return 0;
}

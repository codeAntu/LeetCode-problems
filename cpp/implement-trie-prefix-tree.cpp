#include "math.h"
#include "string"
using namespace std;


class trieNode {
public:
  trieNode* next[26];
  bool isWord;

};


class Trie {
public:

  trieNode* root;

  Trie() {
    root = new trieNode();
  }

  void insert(string word) {
    trieNode* p = root;

    for (char c : word) {
      if (p->next[c - 'a'] == NULL) {
        p->next[c - 'a'] = new trieNode();
      }
      p = p->next[c - 'a'];
    }
    p->isWord = true;
  }

  bool search(string word) {
    trieNode* p = root;
    for (char c : word) {
      if (p->next[c - 'a'] == NULL) {
        return false;
      }
      p = p->next[c - 'a'];
    }
    return p->isWord;
  }

  bool startsWith(string prefix) {
    trieNode* p = root;
    for (char c : prefix) {
      if (p->next[c - 'a'] == NULL) {
        return false;
      }
      p = p->next[c - 'a'];
    }
    return true;
  }
};

int main() {


  return 0;
}
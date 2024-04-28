#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class trieNode {
public:
  trieNode* next[26];
  bool isWord;
};

class WordDictionary {
  trieNode* root;

  bool dfs(string& word, int i, trieNode* trieNode) {
    if (word.length() == i) return trieNode->isWord;

    if (word[i] == '.') {
      for (int j = 0; j < 26; j++) {
        if (trieNode->next[j] != NULL && dfs(word, i + 1, trieNode->next[j])) return true;
      }
      return false;
    } else {
      if (trieNode->next[word[i] - 'a'] == NULL) return false;
      return dfs(word, i + 1, trieNode->next[word[i] - 'a']);
    }

    return false;
  }

public:
  WordDictionary() { root = new trieNode(); }

  void addWord(string word) {
    trieNode* p = root;

    for (char c : word) {
      if (p->next[c - 'a'] == NULL) p->next[c - 'a'] = new trieNode();
      p = p->next[c - 'a'];
    }
    p->isWord = true;
  }

  bool search(string word) { return dfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() { return 0; }
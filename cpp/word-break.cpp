#include <float.h>

#include "math.h"
#include "string"
#include "vector"

using namespace std;

// a trie class

class Trie {
public:
  Trie* children[26];
  bool isEnd;
};

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    Trie* root = new Trie();
    Trie* node = root;
    for (string& word : wordDict) {
      node = root;
      for (char c : word) {
        if (!node->children[c - 'a']) {
          node->children[c - 'a'] = new Trie();
        }
        node = node->children[c - 'a'];
      }
      node->isEnd = true;
    }

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
      node = root;
      for (int j = i; j < n; j++) {
        if (!node->children[s[j] - 'a']) {
          break;
        }
        node = node->children[s[j] - 'a'];
        if (node->isEnd && dp[i]) {
          dp[j + 1] = true;
        }
      }
    }

    return dp[n];
  }
};

int main() {
  Solution s;

  return 0;
}
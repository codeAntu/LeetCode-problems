#include <string>

#include "math.h"
#include "vector"

using namespace std;

class trieNode {
public:
  trieNode* next[26];
  string word = "";
};

class Solution {
  trieNode* root;
  vector<string> ans;

  void addWord(string word) {
    trieNode* p = root;
    for (char c : word) {
      if (p->next[c - 'a'] == NULL) p->next[c - 'a'] = new trieNode();
      p = p->next[c - 'a'];
    }
    p->word = word;
  }

  void search(int i, int j, vector<vector<char>>& board, trieNode* trieNode) {
    if (board[i][j] == '0' || trieNode->next[board[i][j] - 'a'] == NULL) return;

    char c = board[i][j];

    board[i][j] = '0';
    trieNode = trieNode->next[c - 'a'];

    if (trieNode->word != "") {
      ans.push_back(trieNode->word);
      trieNode->word = "";
    }

    if (i > 0) search(i - 1, j, board, trieNode);
    if (i < board.size() - 1) search(i + 1, j, board, trieNode);
    if (j > 0) search(i, j - 1, board, trieNode);
    if (j < board[0].size() - 1) search(i, j + 1, board, trieNode);

    board[i][j] = c;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new trieNode();
    for (string& word : words) {
      addWord(word);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        search(i, j, board, root);
      }
    }

    return ans;
  }
};

int main() {
  // Solution s;

  return 0;
}
#include "math.h"
#include "vector"
#include "string"


using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          if (dfs(board, word, i, j, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
    if (index == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
      return false;
    }
    board[i][j] = '*';
    if (dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) ||
        dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1)) {
      return true;
    }
    board[i][j] = word[index];
    return false;
  }
};

int main() {
  Solution s;

  return 0;
}
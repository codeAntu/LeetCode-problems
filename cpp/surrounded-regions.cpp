#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O') {
      return;
    }
    board[x][y] = '#';
    dfs(board, x + 1, y);
    dfs(board, x - 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
  }

  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) {
      return;
    }

    for (int i = 0; i < board.size(); i++) {
      if (board[i][0] == 'O') dfs(board, i, 0);
      if (board[i][board[0].size() - 1] == 'O') dfs(board, i, board[0].size() - 1);
    }

    for (int i = 0; i < board[0].size(); i++) {
      if (board[0][i] == 'O') dfs(board, 0, i);
      if (board[board.size() - 1][i] == 'O') dfs(board, board.size() - 1, i);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == '#') board[i][j] = 'O';
      }
    }
  }
};

class Solution1 {
public:
  void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
    if (i < 0 or j < 0 or i >= m or j >= n or board[i][j] != 'O') return;
    board[i][j] = '#';
    DFS(board, i - 1, j, m, n);
    DFS(board, i + 1, j, m, n);
    DFS(board, i, j - 1, m, n);
    DFS(board, i, j + 1, m, n);
  }

  void solve(vector<vector<char>>& board) {
    int m = board.size();

    if (m == 0) return;

    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') DFS(board, i, 0, m, n);
      if (board[i][n - 1] == 'O') DFS(board, i, n - 1, m, n);
    }

    // Moving over first and last row
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O') DFS(board, 0, j, m, n);
      if (board[m - 1][j] == 'O') DFS(board, m - 1, j, m, n);
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == '#') board[i][j] = 'O';
      }
  }
};

int main() {
  Solution s;

  return 0;
}
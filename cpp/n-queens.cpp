#include "math.h"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    void dfs(vector<vector<string>>& res, vector<string>& board, vector<int>& cols, vector<int>& diag1, vector<int>& diag2, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;
            board[row][col] = 'Q';
            dfs(res, board, cols, diag1, diag2, row + 1, n);
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        dfs(res, board, cols, diag1, diag2, 0, n);
        return res;      
    }
};

int main() {
  Solution s;


  return 0;
}
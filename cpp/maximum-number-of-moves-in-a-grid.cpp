#include <unordered_map>
#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  int dfs(vector<vector<int>>& grid, int i, int j, int prev) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] <= prev) {
      return 0;
    }

    if (dp[i][j] != 0) return dp[i][j];
    int res = 0;

    res = max(res, 1 + dfs(grid, i - 1, j + 1, grid[i][j]));
    res = max(res, 1 + dfs(grid, i, j + 1, grid[i][j]));
    res = max(res, 1 + dfs(grid, i + 1, j + 1, grid[i][j]));

    dp[i][j] = res;

    return res;
  }

  int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    dp = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      if (res == m) break;
      res = max(res, dfs(grid, i, 0, -1));
    }
    return res - 1;
  }
};

int main() {
  Solution s;

  return 0;
}
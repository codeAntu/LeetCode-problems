#include <corecrt.h>

#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 0)
      return true;

    if (grid1[i][j] != grid2[i][j]) return false;

    grid2[i][j] = 0;

    bool up = dfs(grid1, grid2, i - 1, j);
    bool down = dfs(grid1, grid2, i + 1, j);
    bool left = dfs(grid1, grid2, i, j - 1);
    bool right = dfs(grid1, grid2, i, j + 1);

    return up && down && left && right;
  }

  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();     // Number of rows
    int n = grid1[0].size();  // Number of columns
    int count = 0;            // Counter for sub-islands

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j)) {
          count++;
        }
      }
    }

    return count;
  }
};

int main() {
  Solution s;

  return 0;
}
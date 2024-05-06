#include <algorithm>
#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int x[4] = {0, 0, 1, -1};
  int y[4] = {1, -1, 0, 0};
  int dfs(vector<vector<int>>& grid, int i, int j, int time) {
    grid[i][j] = 0;

    int left = 0, right = 0, up = 0, down = 0;

    for (int i = 0; i < 4; i++) {
      int newI = i + x[i];
      int newJ = j + y[i];
      if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() &&
          grid[newI][newJ] == 1) {
        if (i == 0) {
          left = dfs(grid, newI, newJ, time + 1);
        } else if (i == 1) {
          right = dfs(grid, newI, newJ, time + 1);
        } else if (i == 2) {
          up = dfs(grid, newI, newJ, time + 1);
        } else {
          down = dfs(grid, newI, newJ, time + 1);
        }
      }
    }

    return max(time, max(left, max(right, max(up, down))));
  }

  int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          grid[i][j] = 1;
          ans = dfs(grid, i, j, 0);
        }
      }
    }

    for (auto row : grid) {
      for (auto cell : row) {
        if (cell == 1) {
          return -1;
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  // [[2,1,1],[1,1,0],[0,1,1]]

  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout << s.orangesRotting(grid) << endl;

  return 0;
}
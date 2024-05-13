#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res(n - 2, vector<int>(m - 2, 0));

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        int maxVal = grid[i][j];
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            maxVal = max(maxVal, grid[i + x][j + y]);
          }
        }
        res[i - 1][j - 1] = maxVal;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
#include "vector"
using namespace std;

class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> res;
    int m = land.size(), n = land[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (land[i][j] == 1) {
          int x = i, y = j;
          while (x < m && land[x][j] == 1) x++;
          while (y < n && land[i][y] == 1) y++;
          res.push_back({i, j, x - 1, y - 1});
          for (int a = i; a < x; a++) {
            for (int b = j; b < y; b++) {
              land[a][b] = 0;
            }
          }
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
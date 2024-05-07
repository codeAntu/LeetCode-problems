#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& visited) {
    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j] == 1 ||
        heights[i][j] < prev) {
      return;
    }
    visited[i][j] = 1;
    dfs(heights, i + 1, j, heights[i][j], visited);
    dfs(heights, i - 1, j, heights[i][j], visited);
    dfs(heights, i, j + 1, heights[i][j], visited);
    dfs(heights, i, j - 1, heights[i][j], visited);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> pec(heights.size(), vector<int>(heights[0].size(), 0));
    vector<vector<int>> atl(heights.size(), vector<int>(heights[0].size(), 0));
    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); i++) {
      dfs(heights, i, 0, INT_MIN, pec);
      dfs(heights, i, heights[0].size() - 1, INT_MIN, atl);
    }

    for (int i = 0; i < heights[0].size(); i++) {
      dfs(heights, 0, i, INT_MIN, pec);
      dfs(heights, heights.size() - 1, i, INT_MIN, atl);
    }

    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        if (pec[i][j] == 1 && atl[i][j] == 1) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
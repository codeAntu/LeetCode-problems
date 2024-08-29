#include <bitset>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
  vector<int> row[10001], col[10001];
  bitset<1001> visited;

  void dfs(int i, vector<vector<int>>& stones) {
    visited[i] = true;

    for (int j : row[stones[i][0]]) {
      if (!visited[j]) {
        dfs(j, stones);
      }
    }

    for (int j : col[stones[i][1]]) {
      if (!visited[j]) {
        dfs(j, stones);
      }
    }
  }

public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();

    for (int i = 0; i < n; i++) {
      row[stones[i][0]].push_back(i);
      col[stones[i][1]].push_back(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        ans++;
        dfs(i, stones);
      }
    }

    return n - ans;
  }
};

int main() {
  Solution s;

  return 0;
}
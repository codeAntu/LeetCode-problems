#include <queue>
#include <unordered_set>
#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
  int bfs(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});
    int res = 0;

    while (!q.empty()) {
      auto [u, d] = q.front();
      q.pop();
      if (u == n - 1) {
        return d;
      }
    
      for (int v : edges[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push({v, d + 1});
        }
      }
    }

    return -1;
  }

public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> edges(n, vector<int>(0));
    vector<int> res;

    for (int i = 0; i < n - 1; i++) {
      edges[i].push_back(i + 1);
    }

    for (auto query : queries) {
      int u = query[0];
      int v = query[1];

      edges[u].push_back(v);

      res.push_back(bfs(edges));
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
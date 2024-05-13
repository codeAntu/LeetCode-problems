#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> res;
  bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    if (visited[node] == 1) {
      return false;
    }
    if (visited[node] == 2) {
      return true;
    }
    visited[node] = 1;
    for (auto n : graph[node]) {
      if (!dfs(n, graph, visited)) {
        return false;
      }
    }
    visited[node] = 2;
    res.push_back(node);
    return true;
  }
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
    }
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i, graph, visited)) {
        return {};
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
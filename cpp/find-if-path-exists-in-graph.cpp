#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int source, int destination) {
    if (source == destination) {
      return true;
    }

    visited[source] = true;
    for (int neighbor : graph[source]) {
      if (!visited[neighbor]) {
        if (dfs(graph, visited, neighbor, destination)) {
          return true;
        }
      }
    }

    return false;
  }

  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    return dfs(graph, visited, source, destination);
  }
};

int main() {
  Solution s;

  return 0;
}
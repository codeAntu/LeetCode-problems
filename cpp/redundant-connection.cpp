#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int find(vector<int>& parent, int x) {
    int par = parent[x];

    while (par != parent[par]) {
      parent[par] = parent[parent[par]];
      par = parent[par];
    }
    return par;
  }

  void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX == rootY) {
      return;
    }
    if (rank[rootX] < rank[rootY]) {
      swap(rootX, rootY);
    }
    parent[rootY] = rootX;
    rank[rootX] += rank[rootY];
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int size = edges.size();
    vector<int> parent(size + 1, 0);
    vector<int> rank(size + 1, 1);
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      if (find(parent, u) == find(parent, v)) {
        return edge;
      }
      unite(parent, rank, u, v);
    }
    return {};
  }
};

int main() {
  Solution s;

  return 0;
}
#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//     bool canFinish(int nums, vector<vector<int>>& prerequisites) {
//         map<int, vector<int>> graph;
//         vector<int> indegree(nums, 0);
//         for (auto p : prerequisites) {
//             graph[p[1]].push_back(p[0]);
//             indegree[p[0]]++;
//         }
//         vector<int> q;
//         for (int i = 0; i < nums; i++) {
//             if (indegree[i] == 0) {
//                 q.push_back(i);
//             }
//         }
//         int count = 0;
//         while (!q.empty()) {
//             int node = q.back();
//             q.pop_back();
//             count++;
//             for (auto n : graph[node]) {
//                 indegree[n]--;
//                 if (indegree[n] == 0) {
//                     q.push_back(n);
//                 }
//             }
//         }
//         return count == nums;
//     }
// };

// dfs
class Solution {
public:
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
    return true;
  }
  bool canFinish(int nums, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(nums);
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
    }
    vector<int> visited(nums, 0);
    for (int i = 0; i < nums; i++) {
      if (!dfs(i, graph, visited)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;

  return 0;
}
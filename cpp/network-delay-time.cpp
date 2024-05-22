#include <queue>
#include <unordered_map>
#include <utility>
#include "math.h"
#include "vector"

using namespace std;

// time complexity: O(n^2)
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<int> dist(n + 1, INT_MAX);
//         dist[k] = 0;
//         for (int i = 1; i < n; i++) {
//             for (auto& time : times) {
//                 int u = time[0], v = time[1], w = time[2];
//                 if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }
//         int res = *max_element(dist.begin() + 1, dist.end());
//         return res == INT_MAX ? -1 : res;
//     }
// };

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>> pq;
    int res = 0;

    for (auto& time : times) {
      graph[time[0]].push_back({time[1], time[2]});
    }

    pq.push({0, k});

    while (!pq.empty()) {
      auto [dist, node] = pq.top();
      pq.pop();

      if (visited[node]) {
        continue;
      }

      visited[node] = true;
      res = dist;

      for (auto& [next_node, next_dist] : graph[node]) {
        if (!visited[next_node]) {
          pq.push({dist - next_dist, next_node});
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        return -1;
      }
    }

    return -res;
  }
};

int main() {
  Solution s;

  return 0;
}
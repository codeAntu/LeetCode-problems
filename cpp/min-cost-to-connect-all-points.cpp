#include <queue>
#include <utility>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n, false);
    int cost = 0;
    int visited_count = 0;

    pq.push({0, 0});

    while (visited_count < n) {
      auto [dist, node] = pq.top();
      pq.pop();

      if (visited[node]) {
        continue;
      }

      visited[node] = true;
      visited_count++;
      cost += dist;

      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          int new_dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
          pq.push({-new_dist, i});
        }
      }
    }

    return -cost;
  }
};

int main() {
  Solution s;

  return 0;
}
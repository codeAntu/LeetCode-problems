
#include <cstdint>
#include <queue>
#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
  unordered_map<int, vector<int>> adj;
  unordered_map<int, int> boob_time;

  bool dfs(int src, int pre, int time) {
    if (src == 0) {
      boob_time[src] = time;
      return true;
    }

    for (auto& dst : adj[src]) {
      if (dst == pre) continue;
      if (dfs(dst, src, time + 1)) {
        boob_time[src] = time;
        return true;
      }
    }

    return false;
  }

public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    // adj list
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    // bob path
    dfs(bob, -1, 0);

    // profit
    queue<vector<int>> q;
    int profit = INT64_MIN;

    // node , time , pre , profit
    q.push({0, 0, -1, amount[0]});

    while (!q.empty()) {
      vector<int> front = q.front();
      int node = front[0];
      int time = front[1];
      int pre = front[2];
      int p = front[3];
      q.pop();

      for (auto& dst : adj[node]) {
        if (dst == pre) continue;

        int profit = amount[dst];
        int newTime = time + 1;

        // if this node is abaliable for bob
        if (boob_time.count(dst)) {
          if (boob_time[dst] < newTime) {
            profit = 0;
          }
          if (boob_time[dst] == newTime) {
            profit = amount[dst] / 2;
          }
        }

        q.push({dst, newTime, node, p + profit});
        if (adj[dst].size() == 1) {
          profit = max(profit, p + profit);
        }
      }
    }

    return profit;
  }
};

int main() {
  Solution s;

  return 0;
}
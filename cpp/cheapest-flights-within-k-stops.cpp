#include "math.h"
#include "vector"

using namespace std;

// Bellman-Ford Algorithm
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int INF = 1e9;
    vector<int> price(n, INF);

    price[src] = 0;
      
    for (int i = 0; i <= k; i++) {
      vector<int> temp = price;
      for (auto& flight : flights) {
        int s = flight[0];
        int d = flight[1];
        int p = flight[2];

        if (price[s] != INF && price[s] + p < temp[d]) {
          temp[d] = price[s] + p;
        }
      }
      price = temp;
    }

    return price[dst] == INF ? -1 : price[dst];
  }
};





// This Solution is very slow , only beats 20% of the submissions
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
//         dp[0][src] = 0;
//         for (int i = 1; i <= k + 1; i++) {
//             dp[i][src] = 0;
//             for (vector<int>& flight : flights) {
//                 if (dp[i - 1][flight[0]] != INT_MAX) {
//                     dp[i][flight[1]] = min(dp[i][flight[1]], dp[i - 1][flight[0]] + flight[2]);
//                 }
//             }
//         }
//         return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
//     }
// };

// May be this is a Solution but it takes too much time to run , Time limit exceeded
// class Solution {
// public:
//   unordered_map<int, vector<pair<int, int>>> graph;

//   int dfs(int src, int dst, int k, vector<int>& visited) {
//     if (k < 0) {
//       return -1;
//     }
//     if (src == dst) {
//       return 0;
//     }
//     visited[src] = 1;

//     int res = INT_MAX;

//     for (auto& neighbor : graph[src]) {
//       if (visited[neighbor.first] == 1) {
//         continue;
//       }
//       int subRes = dfs(neighbor.first, dst, k - 1, visited);
//       if (subRes != -1) {
//         res = min(res, subRes + neighbor.second );
//       }
//     }

//     visited[src] = 0;

//     return res == INT_MAX ? -1 : res;
//   }
//   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//     vector<int> visited(n, 0);
//     for (auto& flight : flights) {
//       graph[flight[0]].push_back({flight[1], flight[2]});
//     }

//     int res = dfs(src, dst, k + 1, visited);

//     return res == INT_MAX ? -1 : res;
//   }
// };

int main() {
  Solution s;

  return 0;
}
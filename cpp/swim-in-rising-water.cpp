#include <queue>
#include <utility>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    priority_queue<pair<int, pair<int, int>>> pq;
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int res = 0;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    pq.push({-grid[0][0], {0, 0}});

    while (!pq.empty()) {
      auto [time, pos] = pq.top();
      pq.pop();

      int x = pos.first;
      int y = pos.second;

      if (visited[x][y]) {
        continue;
      }

      visited[x][y] = true;
      res = max(res, -time);

      if (x == n - 1 && y == n - 1) {
        break;
      }

      for (auto& direction : directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
          pq.push({-max(-time, grid[new_x][new_y]), {new_x, new_y}});
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
#include "deque"
#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;
#include <queue>
#include <tuple>
#include <vector>


using namespace std;

#include <deque>
#include <tuple>
#include <vector>


using namespace std;

class Solution {
  int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    deque<tuple<int, int, int>> dq;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    dq.push_front({0, 0, 0});

    while (!dq.empty()) {
      auto [obs, x, y] = dq.front();
      dq.pop_front();

      if (x == n - 1 && y == m - 1) {
        return obs;
      }

      if (visited[x][y]) {
        continue;
      }
      visited[x][y] = 1;

      for (int i = 0; i < 4; i++) {
        int nx = x + pos[i][0];
        int ny = y + pos[i][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
          continue;
        }

        if (grid[nx][ny] == 1) {
          dq.push_back({obs + 1, nx, ny});
        } else {
          dq.push_front({obs, nx, ny});
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}
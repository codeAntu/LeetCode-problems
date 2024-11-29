#include <queue>
#include <tuple>
#include <vector>


using namespace std;

class Solution {
  int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
  int minimumTime(vector<vector<int>>& grid) {
    if (grid[1][0] > 1 && grid[0][1] > 1) return -1;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    pq.push(make_tuple(grid[0][0], 0, 0));

    while (!pq.empty()) {
      auto [t, x, y] = pq.top();
      pq.pop();

      if (x == n - 1 && y == m - 1) {
        return t;
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

        int wait = 0;

        if (abs(grid[nx][ny] - t) % 2 == 0) {
          wait = 1;
        }
        int nt = max(grid[nx][ny] + wait, t + 1);
        pq.push(make_tuple(nt, nx, ny));
      }
    }

    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}
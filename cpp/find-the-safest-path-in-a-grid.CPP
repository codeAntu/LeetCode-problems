#include <algorithm>
#include <queue>
#include <utility>
#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> row = {0, 0, -1, 1};
  vector<int> col = {-1, 1, 0, 0};

  void bfs(vector<vector<int>>& grid, vector<vector<int>>& min_dis) {
    queue<pair<int, int>> q;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          min_dis[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();

      int x = curr.first;
      int y = curr.second;
      int dis = min_dis[x][y];

      for (int i = 0; i < 4; i++) {
        int newX = x + row[i];
        int newY = y + col[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < n && min_dis[newX][newY] > 1 + dis) {
          min_dis[newX][newY] = 1 + dis;
          q.push({newX, newY});
        }
      }
    }
  }

  int maximumSafenessFactor(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return 0;

    vector<vector<int>> min_dis(n, vector<int>(n, INT_MAX));
    bfs(grid, min_dis);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({min_dis[0][0], {0, 0}});

    while (!pq.empty()) {
      pair<int, pair<int, int>> curr = pq.top();
      pq.pop();

      int dis = curr.first;
      int x = curr.second.first;
      int y = curr.second.second;

      if (x == n - 1 && y == n - 1) return dis;
      visited[x][y] = true;

      for (int i = 0; i < 4; i++) {
        int nx = x + row[i];
        int ny = y + col[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
          int s = min(dis, min_dis[nx][ny]);
          pq.push({s, {nx, ny}});
          visited[nx][ny] = true;
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
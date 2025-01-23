#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int countServers(vector<vector<int>>& grid) {
    unordered_map<int, int> row, col;
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          row[i]++;
          col[j]++;
        }
      }
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
          count++;
        }
      }
    }

    return count;
  }
};

int main() {
  Solution s;

  return 0;
}
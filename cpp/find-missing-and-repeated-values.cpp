#include <unordered_map>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int, int> m;
    int n = grid.size();
    vector<int> res(2);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (m.find(grid[i][j]) != m.end()) {
          res[0] = grid[i][j];
        } else {
          m[grid[i][j]]++;
        }
      }
    }

    for (int i = 1; i <= n * n; i++) {
      if (m.find(i) == m.end()) {
        res[1] = i;
        break;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
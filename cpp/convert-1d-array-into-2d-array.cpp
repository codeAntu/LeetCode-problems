#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> res(m, vector<int>(n, 0));

    if (original.size() != m * n) {
      return {};
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res[i][j] = original[i * n + j];
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    long long sum = 0;
    int min_abs = INT_MAX;
    int neg_count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sum += abs(matrix[i][j]);
        min_abs = min(min_abs, abs(matrix[i][j]));
        if (matrix[i][j] < 0) {
          neg_count++;
        }
      }
    }

    if (neg_count % 2 == 1) {
      sum -= 2 * min_abs;
    }

    return sum;
  }
};

int main() {
  Solution s;

  return 0;
}
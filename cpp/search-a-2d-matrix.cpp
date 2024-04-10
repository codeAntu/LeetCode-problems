#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[mid / n][mid % n] == target) return true;
      if (matrix[mid / n][mid % n] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution s;

  return 0;
}

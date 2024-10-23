#include "math.h"
#include "vector"

using namespace std;

  class Solution {
  public:
    int maxWidthRamp(vector<int>& nums) {
      int n = nums.size();
      vector<int> maxRight(n);
      int i = 0, j = 1;
      int res = 0;

      maxRight[n - 1] = nums[n - 1];
      for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], nums[i]);
      }

      while (j < n) {
        if (nums[i] <= maxRight[j]) {
          res = max(res, j - i);
          j++;
        } else {
          i++;
        }
      }

      return res;
    }
  };

int main() {
  Solution s;

  return 0;
}
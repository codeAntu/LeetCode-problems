#include <algorithm>
#include "math.h"
#include "vector"


using namespace std;

// class Solution {
// public:
//   int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n, 1);
//     int maxLen = 1;

//     for (int i = n - 1; i >= 0; i--) {
//       for (int j = i + 1; j < n; j++) {
//         if (nums[i] < nums[j]) {
//           dp[i] = max(dp[i], dp[j] + 1);
//         }
//       }
//       maxLen = max(maxLen, dp[i]);
//     }

//     return maxLen;
//   }
// };

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
      if (nums[i] > dp.back())
        dp.push_back(nums[i]);
      else {
        int low = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        dp[low] = nums[i];
      }
    }
    return dp.size();
  }
};

int main() {
  Solution s;

  return 0;
}
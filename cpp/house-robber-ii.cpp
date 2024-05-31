#include "vector"

using namespace std;

class Solution {
public:
  int helper(vector<int> nums, bool skip) {
    int n = nums.size();
    int rob1 = 0, rob2 = 0;

    for (int i = !skip; i < n - skip; i++) {
      if (i % 2 == 0) {
        rob1 = max(rob1 + nums[i], rob2);
      } else {
        rob2 = max(rob2 + nums[i], rob1);
      }
    }
    return max(rob1, rob2);
  }
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    return max(helper(nums, true), helper(nums, false));
  }
};

int main() {
  Solution s;

  return 0;
}
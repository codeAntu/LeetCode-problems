#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool canSortArray(vector<int>& nums) {
    int n = nums.size();
    int curr_min = 0, curr_max = 0;
    int prev_max = 0;

    for (int i = 0; i < n; i++) {
      if (__builtin_popcount(nums[i]) == __builtin_popcount(curr_min)) {
        curr_min = min(curr_min, nums[i]);
        curr_max = max(curr_max, nums[i]);
      } else {
        if (curr_min < prev_max) { 
          return false;
        }
        prev_max = curr_max;
        curr_min = nums[i];
        curr_max = nums[i];
      }
    }
    return curr_min >= prev_max;
  }
};

int main() {
  Solution s;

  return 0;
}

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subsets;

    for (int i = 0; i < pow(2, nums.size()); i++) {
      vector<int> subset;
      for (int j = 0; j < nums.size(); j++) {
        if (i & (1 << j)) {
          subset.push_back(nums[j]);
        }
      }
      subsets.push_back(subset);
    }
    return subsets;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> subsets = s.subsets(nums);

  return 0;
}
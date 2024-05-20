#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//   int sum = 0;

//   void backtrack(vector<int>& nums, int index, int current) {
//     if (index == nums.size()) {
//       sum += current;
//       return;
//     }
//     backtrack(nums, index + 1, current);
//     backtrack(nums, index + 1, current ^ nums[index]);
//   }

//   int subsetXORSum(vector<int>& nums) {
//     backtrack(nums, 0, 0);
//     return sum;
//   }
// };

class Solution {
public:
  int subsetXORSum(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();

    for (int num : nums) {
      sum |= num;
    }
    return sum << (n - 1);
  }
};

int main() {
  Solution s;

  return 0;
}
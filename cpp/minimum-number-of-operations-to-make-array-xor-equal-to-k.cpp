#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int count = 0;
    for (int num : nums) {
      k ^= num;
    }
    return __builtin_popcount(k);
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  int k = 7;
  cout << s.minOperations(nums, k) << endl;

  return 0;
}
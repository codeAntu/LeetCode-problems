#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int max_OR = 0;
  int n = 0;
  int fun(int i, int now_or, vector<int>& nums) {
    if (i < 0) return (now_or == max_OR) ? 1 : 0;
    int skip = fun(i - 1, now_or, nums);
    int take = fun(i - 1, now_or | nums[i], nums);
    return skip + take;
  }

  int countMaxOrSubsets(vector<int>& nums) {
    n = nums.size();
    for (int i = 0; i < n; i++) {
      max_OR |= nums[i];
    }
    return fun(n - 1, 0, nums);
  }
};

int main() {
  Solution s;

  return 0;
}
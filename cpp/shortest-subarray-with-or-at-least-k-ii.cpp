#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = n + 1;
    int num = 0;
    int i = 0, j = 0;
    vector<int> bitCount(32, 0);

    while (j < n) {
      num |= nums[j];

      for (int bit = 0; bit < 32; bit++) {
        if (nums[j] & (1 << bit)) {
          bitCount[bit]++;
        }
      }

      while (i <= j && num >= k) {
        ans = min(ans, j - i + 1);
        
        for (int bit = 0; bit < 32; bit++) {
          if (nums[i] & (1 << bit)) {
            bitCount[bit]--;
            if (bitCount[bit] == 0) {
              num &= ~(1 << bit);
            }
          }
        }
        i++;
      }

      j++;
    }

    return ans == n + 1 ? -1 : ans;
  }
};

int main() {
  Solution s;

  return 0;
}
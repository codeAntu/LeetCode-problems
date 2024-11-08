#include <cmath>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    vector<int> res(n, 0);
    int max = pow(2, maximumBit) - 1;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
      prefixSum ^= nums[i];
      res[n - i - 1] = prefixSum ^ max;
    }

    return res;
  }
};

int main() { return 0; }
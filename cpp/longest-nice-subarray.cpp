#include "vector"

using namespace std;

class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int l = 0, r = 0, useBits = 0, maxLen = 0;

    for (r = 0; r < nums.size(); r++) {
      while ((useBits & nums[r]) != 0) {
        useBits ^= nums[l++];
      }

      useBits |= nums[r];
      maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
  }
};

int main() {
  Solution s;

  return 0;
}

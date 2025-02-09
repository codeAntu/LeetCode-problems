#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
    long long total = 0;
    long long ans = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i] - i;
      total += i;
      ans += mp[x];
      mp[x]++;
    }

    return total - ans;
  }
};

int main() {
  Solution s;

  return 0;
}
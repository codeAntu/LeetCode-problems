#include <algorithm>
#include <unordered_map>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int longestSquareStreak(vector<int>& nums) {
    unordered_map<int, int> m;

    int res = -1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int sqt = sqrt(nums[i]);

      if (sqt * sqt == nums[i] && m.find(sqt) != m.end()) {
        m[nums[i]] = m[sqt] + 1;
        res = max(res, m[nums[i]]);
      } else {
        m[nums[i]] = 1;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
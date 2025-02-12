#include <algorithm>
#include <unordered_map>
#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int maximumSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    int maxSum = -1;
    bool haspair = false;

    for (int i = 0; i < n; i++) {
      int sum = 0;
      int num = nums[i];
      while (num) {
        sum += num % 10;
        num /= 10;
      }

      if (mp.find(sum) == mp.end()) {
        mp[sum] = {nums[i]};
      } else {
        vector<int>& v = mp[sum];
        v.push_back(nums[i]);
        sort(v.rbegin(), v.rend());
        if (v.size() > 2) {
          v.pop_back();
        }
      }
    }


    for (auto& [sum, v] : mp) {
      if (v.size() > 1) {
        haspair = true;
        maxSum = max(maxSum, v[0] + v[1]);
      }
    }

    if (!haspair) {
      return -1;
    }

    return maxSum;
  }
};

int main() {
  Solution s;

  return 0;
}

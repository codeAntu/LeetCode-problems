#include <queue>
#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    int mod = 1e9 + 7;
    int res = 0;
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
      pq.push({-nums[i], i});
    }

    for (int i = 1; i <= right; i++) {
      auto [val, idx] = pq.top();
      pq.pop();
      if (i >= left) {
        res = (res + (-val)) % mod;
      }
      if (idx + 1 < n) {
        pq.push({val - nums[idx + 1], idx + 1});
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
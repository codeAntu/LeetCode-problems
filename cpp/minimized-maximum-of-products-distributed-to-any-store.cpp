#include <algorithm>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int isPossible(int n, vector<int>& quantities, int x) {
    int total = 0;
    for (int q : quantities) {
      total += q % x == 0 ? q / x : q / x + 1;
    }
    return total <= n;
  }

  int minimizedMaximum(int n, vector<int>& quantities) {
    int left = 1, right = 0;
    int ans = 0;
    for (int q : quantities) {
      right = max(right, q);
    }

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isPossible(n, quantities, mid)) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
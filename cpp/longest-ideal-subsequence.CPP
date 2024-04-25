#include <algorithm>
#include "string"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int longestIdealString(string s, int k) {
    vector<int> dp(26, 0);
    int ans = 0;

    for (char c : s) {
      int curr = c - 'a';
      dp[curr] = dp[curr] + 1;

      for (int i = max(0, curr - k); i <= min(25, curr + k); i++) {
        if (i != curr) {
          dp[curr] = max(dp[curr], dp[i] + 1);
        }
      }

      ans = max(ans, dp[curr]);
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
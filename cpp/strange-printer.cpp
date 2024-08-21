#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int helper(vector<vector<int>>& dp, string& s, int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] > 0) return dp[i][j];
    dp[i][j] = helper(dp, s, i, j - 1) + 1;
    for (int k = i; k < j; k++) {
      if (s[k] == s[j]) {
        dp[i][j] = min(dp[i][j], helper(dp, s, i, k) + helper(dp, s, k + 1, j - 1));
      }
    }
    return dp[i][j];
  }

  int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return helper(dp, s, 0, n - 1);
  }
};

int main() {
  Solution s;

  return 0;
}
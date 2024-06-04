#include <algorithm>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    long dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      dp[i] = INT_MAX;
      for (int c : coins) {
        if (i - c >= 0) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main() {
  Solution s;

  return 0;
}
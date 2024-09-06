#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = 0;

    for (int i = 0; i < m; i++) {
      sum += rolls[i];
    }

    int remaining = mean * (m + n) - sum;

    if (remaining < n || remaining > 6 * n) {
      return {};
    }

    vector<int> ans(n, remaining / n);

    for (int i = 0; i < remaining % n; i++) {
      ans[i]++;
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
#include <vector>

class Solution {
  std::vector<int> memo;

public:
  int fib(int n) {
    memo = std::vector<int>(n + 1, -1);
    return helper(n);
  }

  int helper(int n) {
    if (n == 0 || n == 1)
      return n;
    if (memo[n] != -1)
      return memo[n];
    memo[n] = helper(n - 1) + helper(n - 2);
    return memo[n];
  }
};

int main() { return 0; }

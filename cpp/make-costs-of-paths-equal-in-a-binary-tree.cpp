#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int ans = 0;
   int dfs(int n, int x, vector<int>& cost) {
      if (x > n) return 0;
      int left = dfs(n, 2 * x, cost);
      int right = dfs(n, 2 * x + 1, cost);
      ans += abs(left - right);
      return max(left, right) + cost[x - 1];
   }
   int minIncrements(int n, vector<int>& cost) {
      dfs(n, 1, cost);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

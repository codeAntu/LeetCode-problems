#include <string>
#include <unordered_map>
#include "math.h"

using namespace std;

class Solution {
public:
  int res = 0;
  unordered_map<int, int> memo;

  int dfs(string s, int i) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    if (memo.find(i) != memo.end()) return memo[i];

    int res = dfs(s, i + 1);

    if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
      res += dfs(s, i + 2);
    }

    memo[i] = res;
    return res;
  }

  int numDecodings(string s) { 
    return dfs(s, 0);

   }
};

int main() {
  Solution s;

  return 0;
}
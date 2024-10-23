#include <string>
#include <unordered_set>

#include "math.h"

using namespace std;

class Solution {
public:
  unordered_set<string> set;

  int dfs(string& S, int index) {
    if (index == S.size()) {
      return 0;
    }
    int res = 0;
    string temp = "";
    for (int i = index; i < S.size(); i++) {
      temp += S[i];
      if (set.find(temp) == set.end()) {
        set.insert(temp);
        res = max(res, 1 + dfs(S, i + 1));
        set.erase(temp);
      }
    }
    return res;
  }

  int maxUniqueSplit(string s) { return dfs(s, 0); }
};

int main() {
  Solution s;

  return 0;
}
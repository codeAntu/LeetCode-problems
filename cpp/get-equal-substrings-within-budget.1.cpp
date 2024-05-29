#include "string"
using namespace std;

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int res = 0;
    int n = s.size();
    int cost = 0;

    int l = 0;
    int r = 0;

    while (r < n) {
      cost += abs(s[r] - t[r]);
      while (cost > maxCost) {
        cost -= abs(s[l] - t[l]);
        l++;
      }
      res = max(res, r - l + 1);
      r++;
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
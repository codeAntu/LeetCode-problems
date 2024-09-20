#include "string"

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    if (s.empty()) return s;
    long long prefix = 0, suffix = 0, base = 29, power = 1, lastIndex = 0, mod = 1e9 + 7;

    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a' + 1;

      prefix = ((prefix * base) + c) % mod;

      suffix = (suffix + c * power) % mod;
      power = (power * base) % mod;

      if (prefix == suffix) {
        lastIndex = i;
      }
    }

    string res = s.substr(lastIndex + 1);
    reverse(res.begin(), res.end());
    return res + s;
  }
};

int main() {
  Solution s;

  return 0;
}
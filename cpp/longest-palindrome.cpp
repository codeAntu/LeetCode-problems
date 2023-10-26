#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_map"
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> m;
    int res = 0;
    bool isOdd = false;
    for (char& c : s) {
      m[c]++;
    }
    for (auto& [ch, cnt] : m) {
      if (cnt % 2 == 0) {
        res += cnt;
      } else {
        res += cnt - 1;
        isOdd = true;
      }
    }
    return isOdd ? res + 1 : res;
  }
};

int main() {
  Solution s;


  return 0;
}

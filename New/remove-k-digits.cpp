#include <stack>
#include <string>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    int len = num.length();
    string res = "";
    stack<int> s;
    if (len <= k) return "0";
    for (int i = 0; i < len; i++) {
      int number = num[i] - '0';
      while (!s.empty() && s.top() > number && k > 0) {
        s.pop();
        k--;
      }
      if (number != 0 || !s.empty()) s.push(number);
    }
    while (!s.empty() && k > 0) {
      s.pop();
      k--;
    }
    while (!s.empty()) {
      res.push_back(s.top() + '0');
      s.pop();
    }
    reverse(res.begin(), res.end());
    return res == "" ? "0" : res;
  }
};

int main() {
  Solution s;

  return 0;
}
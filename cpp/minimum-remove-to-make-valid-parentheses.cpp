#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;


class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int n = s.size();
    vector<int> stack;
    string ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stack.push_back(i);
      } else if (s[i] == ')') {
        if (stack.size()) {
          stack.pop_back();
        } else {
          s[i] = '*';
        }
      }
    }

    for (int i = 0; i < stack.size(); i++) {
      s[stack[i]] = '*';
    }

    for (int i = 0; i < n; i++) {
      if (s[i] != '*') ans += s[i];
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
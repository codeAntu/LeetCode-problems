#include <algorithm>
#include <stack>
#include <string>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  string smallestNumber(string pattern) {
    stack<int> s;
    string res = "";

    for (int i = 0; i < pattern.size() + 1; i++) {
      s.push(i + 1);

      while (!s.empty() && (i == pattern.size() || pattern[i] == 'I')) {
        res += to_string(s.top());
        s.pop();
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
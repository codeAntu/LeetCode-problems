#include "string"
using namespace std;

class Solution {
public:
  int numSteps(string s) {
    int res = 0;
    int n = s.size();
    int carry = 0;
    for (int i = n - 1; i > 0; i--) {
      if (s[i] - '0' + carry == 1) {
        carry = 1;
        res += 2;
      } else {
        res += 1;
      }
    }
    return res + carry;
  }
};

int main() {
  Solution s;

  return 0;
}
#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  long long minimumSteps(string s) {
    int l = 0, r = 0;
    long long res = 0;

    for (r = 0; r < s.size(); r++) {
      if (s[r] == '0') {
        res += r - l;
        l++;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
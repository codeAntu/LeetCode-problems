#include <algorithm>

#include "string"

using namespace std;

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int aCount = 0;
    int bCount = 0;
    int lesser = min(x, y);
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c > 'b') {
        result += min(aCount, bCount) * lesser;
        aCount = bCount = 0;
      } else if (c == 'a') {
        if (x < y && bCount > 0) {
          bCount--;
          result += y;
        } else
          aCount++;
      } else {
        if (x > y && aCount > 0) {
          aCount--;
          result += x;
        } else
          bCount++;
      }
    }

    result += min(aCount, bCount) * lesser;

    return result;
  }
};

int main() {
  Solution s;

  return 0;
}
#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int n = s.size();
    int cnt = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '[') {
        cnt--;
      } else {
        cnt++;
      }
      max = std::max(max, cnt);
    }

    return (max + 1) / 2;
  }
};

int main() {
  Solution s;

  return 0;
}
#include <algorithm>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int largestCombination(vector<int>& candidates) {
    int n = candidates.size();
    int res = 0;

    for (int i = 0; i < 32; i++) {
      int count = 0;
      for (int num : candidates) {
        if (num & (1 << i)) {
          count++;
        }
      }
      res = max(count, res);
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
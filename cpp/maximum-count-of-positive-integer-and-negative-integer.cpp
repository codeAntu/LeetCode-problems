#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        pos++;
      else if (nums[i] < 0)
        neg++;
    }

    return pos > neg ? pos : neg;
  }
};

int main() {
  Solution s;

  return 0;
}
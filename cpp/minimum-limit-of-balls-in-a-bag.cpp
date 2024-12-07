#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = *max_element(nums.begin(), nums.end());

    while (l < r) {
      int mid = l + (r - l) / 2;
      int count = 0;

      for (int n : nums) {
        count += (n - 1) / mid;
        if (count > maxOperations) {
          break;
        }
      }

      if (count > maxOperations) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return r;
  }
};

int main() {
  Solution s;

  return 0;
}
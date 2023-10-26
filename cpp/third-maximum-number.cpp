#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  int thirdMax(vector<int>& nums) {
    int first = INT_MIN - 1, second = INT_MIN - 1, third = INT_MIN - 1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == first || nums[i] == second || nums[i] == third) continue;
      if (nums[i] > first) {
        third = second;
        second = first;
        first = nums[i];
      } else if (nums[i] > second) {
        third = second;
        second = nums[i];
      } else if (nums[i] > third) {
        third = nums[i];
      }
    }
    return third == INT_MIN - 1 ? first : third;
  }
};

int main() {
  Solution s;


  return 0;
}

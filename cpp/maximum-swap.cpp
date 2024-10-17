#include <string>

#include "math.h"

using namespace std;

class Solution {
public:
  int maximumSwap(int num) {
    string nums = to_string(num);
    char max = '0';
    int maxIndex = -1;
    int leftIndex = -1;
    int rightIndex = -1;

    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] > max) {
        max = nums[i];
        maxIndex = i;
      } else if (nums[i] < max) {
        leftIndex = i;
        rightIndex = maxIndex;
      }
    }

    if (leftIndex == -1) {
      return num;
    }

    swap(nums[leftIndex], nums[rightIndex]);

    return stoi(nums);
  }
};

int main() {
  Solution s;

  return 0;
}
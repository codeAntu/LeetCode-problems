#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int numsSize = nums.size();
    vector<bool> arr(numsSize + 1, false);
    vector<int> res;

    for (int i = 0; i < numsSize; i++) {
      arr[nums[i]] = true;
    }
    for (int i = 1; i <= numsSize; i++) {
      if (!arr[i]) {
        res.push_back(i);
      }
    }

    return res;
  }
};

int main() {
  Solution s;


  return 0;
}

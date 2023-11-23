#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int differenceOfSum(vector<int>& nums) {
      int eleSum = 0;
      int digitSum = 0;

      for (int i = 0; i < nums.size(); i++) {
         eleSum += nums[i];
         while (nums[i]) {
            digitSum += nums[i] % 10;
            nums[i] /= 10;
         }
      }

      return eleSum - digitSum;
   }
};

int main() {
   Solution s;

   return 0;
}

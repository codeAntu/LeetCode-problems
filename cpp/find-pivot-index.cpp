#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int pivotIndex(vector<int>& nums) {
      int sum = 0, currSum = 0;
      for (int n : nums) {
         sum += n;
      }
      for (int i = 0; i < nums.size(); i++) {
         if (currSum == sum - currSum - nums[i]) return i;
         currSum += nums[i];
      }
      return -1;
   }
};

int main() {
   Solution s;


   return 0;
}
#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int missingNumber(vector<int>& nums) {
      int len = nums.size();
      int sum = (len * (len + 1)) / 2;

      for (int i = 0; i < len; i++)
      {
         sum -= nums[i];
      }
      return sum;
   }
};


int main() {
   Solution s;


   return 0;
}
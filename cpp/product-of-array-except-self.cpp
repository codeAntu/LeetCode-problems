#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();
      int product = 1;
      int a = 0;
      for (int i = 0; i < len; i++) {
         if (nums[i] == 0) a++;
         else product *= nums[i];
      }
      if (a) {
         for (int i = 0; i < len; i++) {
            if (nums[i]) nums[i] = 0;
            else if (a > 1) nums[i] = 0;
            else nums[i] = product;
         }
      } else
      {
         for (int i = 0; i < len; i++) {
            nums[i] = product / nums[i];
         }
      }

      return nums;
   }
};

int main() {
   Solution s;


   return 0;
}
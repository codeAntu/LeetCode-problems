#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   void moveZeroes(vector<int>& nums) {
      int count = 0;
      int n = nums.size();

      for (int i = 0; i < n; i++)
      {
         if (nums[i] == 0) {
            count++;
            continue;
         }
         nums[i - count] = nums[i];
      }
      while (count)
      {
         nums[n - count] = 0;
         count--;
      }

   }
};

int main() {
   Solution s;


   return 0;
}
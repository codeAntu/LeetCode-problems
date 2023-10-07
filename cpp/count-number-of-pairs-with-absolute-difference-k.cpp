#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   int countKDifference(vector<int>& nums, int k) {
      int  n = nums.size();
      int count = 0;
      for (int i = 0; i < n - 1; i++)
      {
         for (int j = i; j < n; j++)
         {
            if (nums[i] - nums[j] == k or nums[j] - nums[i] == k) count++;
         }
      }
      return count;
   }
};


int main() {
   Solution s;


   return 0;
}
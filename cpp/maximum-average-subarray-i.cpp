#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   double findMaxAverage(vector<int>& nums, int k) {
      int i = 0, sum = 0, max = 0;

      while (i < k) {
         sum += nums[i];
         i++;
      }
      max = sum;

      for (i = k; i < nums.size(); i++)
      {
         sum = sum + nums[i] - nums[i - k];
         if (sum > max) max = sum;
      }

      return max * 1.0 / k;
   }
};

int main() {
   Solution s;


   return 0;
}
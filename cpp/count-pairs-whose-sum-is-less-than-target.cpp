#include "iostream"
#include "math.h"
#include "vector"
#include "map"

using namespace std;

int countPairs(int* nums, int numsSize, int target) {
   int count = 0, left = 0, right = 0;


}

class Solution {
public:
   int countPairs(vector<int>& nums, int target) {
      int count = 0, left = 0, right = nums.size() - 1;

      sort(nums.begin(), nums.end());

      while (left < right)
      {
         if (nums[left] + nums[right] < target) {
            count += right - left; // update the count
            left++;
         } else
            right--;

      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}
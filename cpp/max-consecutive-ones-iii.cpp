#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int longestOnes(vector<int>& nums, int k) {
      int count = 0, max = 0, zerros = 0;

      for (int i = 0; i < nums.size(); i++) {
         if (nums[i]) count++;
         else {
            zerros++;
            if (zerros <= k) count++;
         }
         while (zerros > k) {
            if (nums[i - count] == 1) count--;
            else zerros--;
         }
         if (count > max) max = count;
      }
      return max;
   }
};

int main() {
   Solution s;

   vector<int> arr = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };

   s.longestOnes(arr, 3);
   return 0;
}
#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   int longestSubarray(vector<int>& nums) {
      int righ = 0, left = 0, zerros = 0, max = 0;

      for (righ = 0; righ < nums.size(); righ++) {
         if (nums[righ] == 0) zerros++;
         if (zerros > 1 && nums[left++] == 0) {
            zerros--;
         }
         if (righ - left > max) max = righ - left;
      }
      return max;
   }
};

int main() {
   Solution s;


   return 0;
}
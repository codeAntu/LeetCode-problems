#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool increasingTriplet(vector<int>& nums) {
      int first = INT_MAX, sec = INT_MAX;
      int len = nums.size();
      for (int i = 0; i < len; i++) {
         if(first >= nums[i]) first = nums[i];
         else if(sec >= nums[i]) sec = nums[i];
         else return true;
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}
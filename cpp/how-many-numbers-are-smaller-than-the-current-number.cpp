#include "iostream"
#include "math.h"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
   vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> res(nums.size());
      int count = 0;
      for (int i = 0; i < nums.size(); i++) {
         for (int j = 0; j < nums.size(); j++) {
            if (nums[i] > nums[j]) count++;
         }
         res[i] = count;
         count = 0;
      }
      return res;
   }
};


int main() {
   Solution s;


   return 0;
}
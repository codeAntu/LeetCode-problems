#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> buildArray(vector<int>& nums) {
      vector<int> arr;
      int n = nums.size();
      for (int i = 0; i < n; i++)
      {
         arr.push_back(nums[nums[n]]);
      }
      
      return arr;
   }
};

int main() {
   Solution s;


   return 0;
}
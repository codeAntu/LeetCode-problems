#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
      int n = nums.size();
      vector<string> ans;
      for (int i = 0; i < n; i++)
      {
         string s = {};
         int  j = i;
         while (j < n - 1 && nums[j + 1] == nums[j] + 1)
         {
            j++;
         }
         if (j > i) {
            s += to_string(nums[i]);
            s += "->";
            s += to_string(nums[j]);
         } else {
            s += to_string(nums[i]);
         }
         ans.push_back(s);
         i = j;
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}
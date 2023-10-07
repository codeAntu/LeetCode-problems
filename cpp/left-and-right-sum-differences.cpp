#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> leftRightDifference(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n);
      int temp = 0;
      for (int i = 0; i < n;i++) {
         temp += nums[i];
         ans[i] = temp;
      }
      temp = 0;
      for (int i = n - 1; i >= 0;i--) {
         temp += nums[i];
         ans[i] = abs(ans[i] - temp);
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}
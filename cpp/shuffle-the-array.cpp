#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> ans(n*2);
      for (int i = 0; i < n; i++) {
         ans[i*2] = nums[i];
         ans[i*2+1] = nums[i+n];
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}
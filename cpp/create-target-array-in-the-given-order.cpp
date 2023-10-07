#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      vector<int> ans;
      int n = nums.size();
      for (int i = 0;i < n;i++) {
         ans.insert( ans.begin() + index[i], nums[i]);
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}
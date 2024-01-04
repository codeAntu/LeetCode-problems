#include "algorithm"
#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   vector<vector<int>> threeSum(vector<int>& nums) {
      int x, y, z;
      vector<vector<int>> ans;

      sort(nums.begin(), nums.end());

      for (x = 0; x < nums.size(); x++) {
         if (x > 0 && nums.size() - x >= 3 && nums[x] == nums[x - 1]) continue;  // skip duplicates

         y = x + 1;
         z = nums.size() - 1;

         while (y < z) {
            if (nums[x] + nums[y] + nums[z] > 0) {
               z--;
            } else if (nums[x] + nums[y] + nums[z] < 0) {
               y++;
            } else {
               vector<int> temp = {nums[x], nums[y], nums[z]};
               ans.push_back(temp);
               while (y < z && nums[y] == temp[1]) y++;
               while (y < z && nums[z] == temp[2]) z--;
            }
         }
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

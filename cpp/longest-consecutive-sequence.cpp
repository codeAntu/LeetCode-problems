#include "iostream"
#include "map"
#include "math.h"
#include "set"
#include "vector"
using namespace std;

class Solution {
  public:
   int longestConsecutive(vector<int>& nums) {
      int i, j, n = nums.size(), ans = 0;

      set<int> s;
      for (i = 0; i < n; i++) {
         s.insert(nums[i]);
      }

      for (i = 0; i < n; i++) {
         if (s.find(nums[i] - 1) == s.end()) {
            j = nums[i] + 1;
            while (s.find(j) != s.end()) {
               j++;
            }
            ans = max(ans, j - nums[i]);
         }
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

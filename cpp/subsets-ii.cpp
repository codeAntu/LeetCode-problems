
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
   vector<vector<int>> res;

   void backtrack(vector<int>& nums, int start, vector<int>& subset) {
      res.push_back(subset);
      for (int i = start; i < nums.size(); i++) {
         if (i > start && nums[i] == nums[i - 1]) continue;  // skip duplicates
         subset.push_back(nums[i]);
         backtrack(nums, i + 1, subset);
         subset.pop_back();
      }
   }

   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> subset;
      sort(nums.begin(), nums.end());
      backtrack(nums, 0, subset);
      return res;
   }
};

int main() {
   Solution s;

   return 0;
}
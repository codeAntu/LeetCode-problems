

class Solution {
public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> nums(nums1.begin(), nums1.end());
      vector<int> ans;
      for (auto n : nums2)
         if (nums.erase(n)) {
            ans.push_back(n);
         }
      return ans;
   }
};

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nums;
    vector<int> ans;

    for (int num : nums1) {
      nums[num]++;
    }
    for (auto n : nums2)
      if (nums[n]) {
        ans.push_back(n);
        nums[n]--;
      }
    return ans;
  }
};
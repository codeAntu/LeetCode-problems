#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//     void dfs(vector<int>& nums, int depth, vector<int>& path, vector<bool>& used,
//     vector<vector<int>>& res) {
//         if (depth == nums.size()) {
//             res.push_back(path);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (used[i]) continue;
//             path.push_back(nums[i]);
//             used[i] = true;
//             dfs(nums, depth + 1, path, used, res);
//             path.pop_back();
//             used[i] = false;
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> path;
//         vector<bool> used(nums.size(), false);
//         dfs(nums, 0, path, used, res);
//         return res;
//     }
// };

class Solution {
public:
  void dfs(vector<int>& nums, int index, vector<vector<int>>& res) {
    if (index == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      swap(nums[index], nums[i]);
      dfs(nums, index + 1, res);
      swap(nums[index], nums[i]);
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(nums, 0, res);
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
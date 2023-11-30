#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
   vector<vector<int>> ans;
   vector<int> temp;
   int sum = 0;
   int target = 0;

   void dfs(TreeNode *root) {
      if (root == nullptr) return;
      sum += root->val;
      temp.push_back(root->val);
      if (!root->left && !root->right && sum == target) {
         ans.push_back(temp);
      } else {
         dfs(root->left);
         dfs(root->right);
      }
      temp.pop_back();
      sum -= root->val;
      return;
   }

   vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
      target = targetSum;
      dfs(root);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

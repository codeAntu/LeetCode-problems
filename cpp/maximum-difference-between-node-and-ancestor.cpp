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
   int dfs(TreeNode *root, int min, int max) {
      if (root == nullptr) return max - min;
      min = std::min(min, root->val);
      max = std::max(max, root->val);
      int l = dfs(root->left, min, max);
      int r = dfs(root->right, min, max);
      return std::max(l, r);
   }
   int maxAncestorDiff(TreeNode *root) {
      return dfs(root, root->val, root->val);
   }
};

class Solution {
  public:
   int ans = 0;
   void dfs(TreeNode *root, int min, int max) {
      if (root == nullptr) {
         ans = std::max(ans, max - min);
         return;
      }
      min = std::min(min, root->val);
      max = std::max(max, root->val);
      dfs(root->left, min, max);
      dfs(root->right, min, max);
   }
   int maxAncestorDiff(TreeNode *root) {
      dfs(root, root->val, root->val);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

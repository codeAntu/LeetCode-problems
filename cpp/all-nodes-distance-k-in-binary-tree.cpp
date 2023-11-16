#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
   vector<int> ans;
   int findDepth(TreeNode* root, TreeNode* target) {
      if (!root) return -1;
      if (root == target) return 0;
      int left = findDepth(root->left, target);
      int right = findDepth(root->right, target);
      if (left == -1 && right == -1) return -1;
      return left == -1 ? right + 1 : left + 1;
   }
   void dfs(TreeNode* root, TreeNode* targetNode, int k, int depth, int target) {
      if (!root) return;
      if (root != targetNode && (abs(depth - target) == k || depth + target == k)) {
         ans.push_back(root->val);
         return;
      }
      dfs(root->left, targetNode, k, depth + 1, target);
      dfs(root->right, targetNode, k, depth + 1, target);
   }
   vector<int>
   distanceK(TreeNode* root, TreeNode* target, int k) {
      if (!root) return ans;
      if (k == 0) {
         ans.push_back(target->val);
         return ans;
      }
      int depth = findDepth(root, target);
      dfs(root, target, k, 0, depth);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

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
   int depth = 0;
   TreeNode *ans = nullptr;
   int findDepth(TreeNode *root) {
      if (!root) return 0;
      return 1 + max(findDepth(root->left), findDepth(root->right));
   }
   bool findSubtree(TreeNode *root, int level) {
      if (!root) {
         if (level == depth) return true;
         return false;
      }
      bool left = findSubtree(root->left, level + 1);
      bool right = findSubtree(root->right, level + 1);
      if (left && right) ans = root;
      return left || right;
   }
   TreeNode *subtreeWithAllDeepest(TreeNode *root) {
      depth = findDepth(root);
      findSubtree(root, 0);
      return ans;
   }
};
class Solution {
  public:
   int depth = 0;
   TreeNode *ans = nullptr;
   int helper(TreeNode *root, int level) {
      if (!root) return level;
      int left = helper(root->left, level + 1);
      int right = helper(root->right, level + 1);
      if (left == right && left >= depth) {
         ans = root;
         depth = left;
      }
      return max(left, right);
   }
   TreeNode *
   subtreeWithAllDeepest(TreeNode *root) {
      helper(root, 0);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

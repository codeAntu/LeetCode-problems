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
   void helper(TreeNode *root, TreeNode *temp, int level) {
      if (!root) return;
      helper(root->left, temp->right, level + 1);
      if (level % 2 == 0) {
         swap(root->val, temp->val);
      }
      helper(root->right, temp->left, level + 1);
   }

   TreeNode *
   reverseOddLevels(TreeNode *root) {
      if (root == nullptr) return nullptr;
      TreeNode *temp = new TreeNode();
      temp = root;
      helper(root->left, temp->right, 0);
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

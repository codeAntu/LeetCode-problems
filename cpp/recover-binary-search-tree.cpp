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
   TreeNode *first = nullptr;
   TreeNode *second = nullptr;
   TreeNode *prev = new TreeNode(INT_MIN);
   void helper(TreeNode *root) {
      if (!root) return;
      helper(root->left);
      if (!first && root->val < prev->val) first = prev;
      if (first && root->val < prev->val) second = root;
      prev = root;
      helper(root->right);
   }
   void recoverTree(TreeNode *root) {
      helper(root);
      swap(first->val, second->val);
   }
};

int main() {
   Solution s;

   return 0;
}

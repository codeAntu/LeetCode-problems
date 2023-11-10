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
   TreeNode *construct(TreeNode *root, int val) {
      if (!root) return new TreeNode(val);
      if (root->val < val) {
         TreeNode *node = new TreeNode(val);
         node->left = root;
         return node;
      }
      root->right = construct(root->right, val);
      return root;
   }
   TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
      root = construct(root, val);
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

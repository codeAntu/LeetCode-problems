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
   TreeNode *insertIntoBST(TreeNode *root, int val) {
      if (root == nullptr) return new TreeNode(val);
      if (root->val > val)
         root->left = insertIntoBST(root->left, val);
      else
         root->right = insertIntoBST(root->right, val);
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

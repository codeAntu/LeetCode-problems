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
   void flatten(TreeNode *root) {
      helper(root);
   }
   TreeNode *prev = NULL;
   void helper(TreeNode *root) {
      if (root == NULL) {
         return;
      }
      helper(root->right);
      helper(root->left);
      root->right = prev;
      root->left = NULL;
      prev = root;
   }
};

int main() {
   Solution s;

   return 0;
}

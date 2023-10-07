#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root || root == p || root == q) return root;

      TreeNode* left = NULL, * right = NULL, * curr = NULL;
      
      if (root->left) left = lowestCommonAncestor(root->left, p, q);
      if (root->right) right = lowestCommonAncestor(root->right, p, q);

      if (left == NULL) return right;
      else if (right == NULL) return left;
      else return root;

   }
};

int main() {
   Solution s;


   return 0;
}
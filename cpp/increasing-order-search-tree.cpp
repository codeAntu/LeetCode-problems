#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   void inorder(TreeNode* root, TreeNode*& cur) {
      if (!root) return;
      inorder(root->left, cur);
      root->left = NULL;
      cur->right = root;
      cur = cur-> right;
      inorder(root->right, cur);
   }
   TreeNode* increasingBST(TreeNode* root) {
      TreeNode* ans = new TreeNode(0);
      TreeNode* cur = ans;
      inorder(root, cur);
      return ans->right;
   }
};

int main() {
   Solution s;


   return 0;
}
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
   TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
      if (preStart == preEnd) return NULL;
      TreeNode *root = new TreeNode(preorder[preStart]);
      int rootIndex = inStart;
      while (inorder[rootIndex] != preorder[preStart]) rootIndex++;
      int leftSize = rootIndex - inStart;
      root->left = build(preorder, inorder, preStart + 1, preStart + leftSize + 1, inStart, rootIndex);
      root->right = build(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
      return root;
   }

   TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
   }
};

int main() {
   Solution s;

   return 0;
}

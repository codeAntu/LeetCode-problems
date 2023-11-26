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
   TreeNode *build(vector<int> &preorder, vector<int> &postorder, int preStart, int preEnd, int postStart, int postEnd) {
      if (preStart == preEnd) return NULL;
      TreeNode *root = new TreeNode(preorder[preStart]);
      if (preStart + 1 == preEnd) return root;
      int rootIndex = postStart;
      while (postorder[rootIndex] != preorder[preStart + 1]) rootIndex++;
      int leftSize = rootIndex - postStart + 1;
      root->left = build(preorder, postorder, preStart + 1, preStart + leftSize + 1, postStart, rootIndex + 1);
      root->right = build(preorder, postorder, preStart + leftSize + 1, preEnd, rootIndex + 1, postEnd - 1);
      return root;
    }

   TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
      return build(preorder, postorder, 0, preorder.size(), 0, postorder.size());
   }
};

int main() {
   Solution s;

   return 0;
}

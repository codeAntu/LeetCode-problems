#include "iostream"
#include "map"
#include "math.h"
#include "unordered_map"
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
   TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd) {
      if (inStart > inEnd) return nullptr;
      TreeNode *root = new TreeNode(postorder[postEnd]);
      int rootIndex = 0;

      for (int i = inStart; i <= inEnd; i++) {
         if (inorder[i] == root->val) {
            rootIndex = i;
            break;
         }
      }
      int leftSize = rootIndex - inStart;
      root->left = build(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
      root->right = build(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
      return root;
   }
   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
   }
};

class Solution {
  public:
   TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int> &m) {
      if (inStart > inEnd) return nullptr;
      TreeNode *root = new TreeNode(postorder[postEnd]);
      int rootIndex = m[root->val];
      int leftSize = rootIndex - inStart;
      root->left = build(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1, m);
      root->right = build(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1, m);
      return root;
   }
   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      unordered_map<int, int> m;
      for (int i = 0; i < inorder.size(); i++) {
         m[inorder[i]] = i;
      }
      return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
   }
};

int main() {
   Solution s;

   return 0;
}

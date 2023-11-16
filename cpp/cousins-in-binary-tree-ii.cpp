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
   void depthSum(TreeNode *root, vector<int> &sums, int depth) {
      if (root == nullptr) return;
      if (depth >= sums.size()) {
         sums.push_back(0);
      }
      sums[depth] += root->val;
      depthSum(root->left, sums, depth + 1);
      depthSum(root->right, sums, depth + 1);
   }

   int maxDepth(TreeNode *root) {
      if (root == nullptr) return 0;
      return 1 + max(maxDepth(root->left), maxDepth(root->right));
   }

   void fill(TreeNode *root, vector<int> &sums, int depth) {
      if (root == nullptr) return;
      int del = 0;
      if (root->left) del += root->left->val;
      if (root->right) del += root->right->val;

      if (root->left) root->left->val = sums[depth + 1] - del;
      if (root->right) root->right->val = sums[depth + 1] - del;

      fill(root->left, sums, depth + 1);
      fill(root->right, sums, depth + 1);
   }

   TreeNode *
   replaceValueInTree(TreeNode *root) {
      if (root == nullptr) return root;
      root->val = 0;
      int max = maxDepth(root);
      vector<int> sums(max, 0);
      depthSum(root, sums, 0);
      fill(root, sums, 0);
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

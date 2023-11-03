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
   vector<int> v;
   void visit(TreeNode *root) {
      if (root == NULL) return;
      visit(root->left);
      v.push_back(root->val);
      visit(root->right);
   }

   TreeNode *build(int l, int r) {
      if (l > r) return NULL;
      int mid = (l + r) / 2;
      TreeNode *root = new TreeNode(v[mid]);
      root->left = build(l, mid - 1);
      root->right = build(mid + 1, r);
      return root;
   }

   TreeNode *balanceBST(TreeNode *root) {
      visit(root);
      return build(0, v.size() - 1);
   }
};

int main() {
   Solution s;

   return 0;
}

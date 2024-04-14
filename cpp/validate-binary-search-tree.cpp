#include "math.h"

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
  bool isValidBST(TreeNode *root, double min = -INFINITY, double max = INFINITY) {
    if (root == nullptr) return true;
    if (root->val <= min || root->val >= max) return false;
    if (root->left != nullptr && root->left->val >= root->val) return false;
    if (root->right != nullptr && root->right->val <= root->val) return false;
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
  }
};

int main() {
  Solution s;

  return 0;
}
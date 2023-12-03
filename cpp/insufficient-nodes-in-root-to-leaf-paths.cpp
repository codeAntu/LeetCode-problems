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
   TreeNode *sufficientSubset(TreeNode *root, int limit, int sum = 0) {
      if (!root) return NULL;
      sum += root->val;
      if (!root->left && !root->right) return sum < limit ? NULL : root;
      root->left = sufficientSubset(root->left, limit, sum);
      root->right = sufficientSubset(root->right, limit, sum);
      if (!root->left && !root->right) return NULL;
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

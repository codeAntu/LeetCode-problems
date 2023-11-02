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
   int ans = 0;
   int dfs(TreeNode *root) {
      if (root == nullptr) return 0;
      int left = dfs(root->left);
      int right = dfs(root->right);
      ans = max(ans, left + right);
      return max(left, right) + 1;
   }
   int diameterOfBinaryTree(TreeNode *root) {
      dfs(root);
      return ans;
   }
};
int main() {
   Solution s;

   return 0;
}

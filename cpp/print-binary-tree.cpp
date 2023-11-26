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
   int getHight(TreeNode *root) {
      if (root == NULL) return 0;
      return max(getHight(root->left), getHight(root->right)) + 1;
   }
   void fill(vector<vector<string>> &res, TreeNode *root, int level, int left, int right) {
      if (root == nullptr) return;
      int mid = (left + right) / 2;
      res[level][mid] = to_string(root->val);
      fill(res, root->left, level + 1, left, mid - 1);
      fill(res, root->right, level + 1, mid + 1, right);
   }
   vector<vector<string>> printTree(TreeNode *root) {
      int high = getHight(root);
      int width = pow(2, high) - 1;
      vector<vector<string>> res(high, vector<string>(width, ""));
      fill(res, root, 0, 0, width - 1);
      return res;
   }
};

int main() {
   Solution s;

   return 0;
}

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
   void traversal(TreeNode *root) {
      if (root) {
         traversal(root->left);
         v.push_back(root->val);
         traversal(root->right);
      }
   }
   int minDiffInBST(TreeNode *root) {
      int minDiff = INT_MAX;
      traversal(root);
      for (int i = 0; i < v.size() - 1; i++) {
         minDiff = min(minDiff, v[i + 1] - v[i]);
      }
      return minDiff;
   }
};

int main() {
   Solution s;

   return 0;
}

#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   int gotoLeft(TreeNode* root, int count) {
      if (!root) return count - 1;
      int m = 0, n = 0;
      if (root->left) n = gotoLeft(root->left, 1);
      if (root->right) m = gotoRight(root->right, count + 1);
      return max(count, max(m, n));
   }

   int gotoRight(TreeNode* root, int count) {
      if (!root) return count - 1;
      int m = 0, n = 0;
      if (root->left) n = gotoLeft(root->left, count + 1);
      if (root->right) m = gotoRight(root->right, 1);
      return max(count, max(m, n));
   }
   int longestZigZag(TreeNode* root) {
      return max(gotoLeft(root->left, 1), gotoRight(root->right, 1));
   }
};


int main() {
   Solution s;


   return 0;
}
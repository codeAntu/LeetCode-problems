#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   TreeNode *left;
   int val;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode *right;
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  public:
   int left = 0, right = 0;

   int count(TreeNode *root, int x = -1) {
      if (!root) return 0;
      int l = count(root->left, x);
      int r = count(root->right, x);
      if (root->val == x) {
         left = l;
         right = r;
      }
      return l + r + 1;
   }

   bool btreeGameWinningMove(TreeNode *root, int n, int x) {
      count(root, x);
      return max(max(left, right), n - left - right - 1) > n / 2;
   }
};

int main() {
   Solution s;

   return 0;
}

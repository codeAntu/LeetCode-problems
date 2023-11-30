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
   pair<int, bool> countTime(TreeNode *root, int start) {
      if (!root) return {0, false};
      int temp;
      auto left = countTime(root->left, start);
      auto right = countTime(root->right, start);
      if (root->val == start) {
         temp = max(left.first, right.first);
         ans = max(ans, temp);
         return {0, true};
      }
      if (left.second) {
         temp = left.first + right.first + 1;
         ans = max(ans, temp);
         return {left.first + 1, true};
      }
      if (right.second) {
         temp = right.first + left.first + 1;
         ans = max(ans, temp);
         return {right.first + 1, true};
      }
      int time = max(left.first, right.first);
      return {time + 1, false};
   }
   int amountOfTime(TreeNode *root, int start) {
      countTime(root, start);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

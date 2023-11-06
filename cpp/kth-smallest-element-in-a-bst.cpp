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
   int count = 0;
   int ans = 0;
   int kthSmallest(TreeNode *root, int k) {
      if (root == NULL) return 0;
      kthSmallest(root->left, k);
      count++;
      if (count == k) {
         ans = root->val;
         return ans;
      }
      kthSmallest(root->right, k);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

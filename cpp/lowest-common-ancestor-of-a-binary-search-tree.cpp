#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* ans = root;

      while (true) {
         if (p->val < ans->val && q->val < ans->val) {
            ans = ans->left;
         } else if (p->val > ans->val && q->val > ans->val) {
            ans = ans->right;
         } else {
            break;
         }
      }
      return ans;
   }
};

class Solution {
  public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == NULL) {
         return NULL;
      }
      if (root->val > p->val && root->val > q->val) {
         return lowestCommonAncestor(root->left, p, q);
      } else if (root->val < p->val && root->val < q->val) {
         return lowestCommonAncestor(root->right, p, q);
      } else {
         return root;
      }
   }
};

int main() {
   Solution s;

   return 0;
}

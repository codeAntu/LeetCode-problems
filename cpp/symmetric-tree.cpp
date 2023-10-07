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
// done
   bool fun(TreeNode* p, TreeNode* q) {
      if (p && q)
      {
         if (p->val != q->val) return false;
         return fun(p->left, q->right) && fun(p->right, q->left);
      }
      if (p || q) return false;
      return true;
   }
   bool isSymmetric(TreeNode* root) {
      if (root)
         return fun(root->left, root->right);

      return true;
   }
};

int main() {
   Solution s;


   return 0;
}
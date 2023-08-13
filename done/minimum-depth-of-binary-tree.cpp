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
   int comp(int n, int m) {
      return m > n ? n : m;
   }
   int fun(TreeNode* root, int n) {
      n++;
      if (root->right && root->left) return comp(fun(root->left, n), fun(root->right, n));
      if (root->left) return fun(root->left, n);
      if (root->right) return fun(root->right, n);
      return n;

   }
   int minDepth(TreeNode* root) {
      if (root)
         return fun(root, 0);
      return 0;
   }
};

int main() {
   Solution s;


   return 0;
}
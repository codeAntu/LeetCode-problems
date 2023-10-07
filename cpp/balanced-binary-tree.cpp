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
   bool isBalanced(TreeNode* root) {
      if (!root) return true;
      if (fun(root, 0) == -1) return false;
      return true;
   }
   int fun(TreeNode* root, int i) {
      if (root) {
         i++;
         int m = fun(root->left, i);
         int n = fun(root->right, i);

         if (m == -1 || n == -1) return -1;
         if (abs(m - n) > 1) return -1;

         return m > n ? m : n;
      }
      return i;
   }
};



int main() {
   Solution s;


   return 0;
}
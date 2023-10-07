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
   vector<int> ans;
   void fun(TreeNode* root) {
      if (root)
      {
         fun(root->left);
         fun(root->right);
         ans.push_back(root->val);
      }
   }
   vector<int> postorderTraversal(TreeNode* root) {
      fun(root);
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}
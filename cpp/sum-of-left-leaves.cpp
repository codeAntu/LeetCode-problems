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
   int sumOfLeftLeaves(TreeNode* root , bool left = false) {
      if (!root) return 0;
      if(!root->left && !root->right) return left ? root->val: 0;
      return sumOfLeftLeaves(root->left , true) + sumOfLeftLeaves(root->right , false);
   }
};


int main() {
   Solution s;


   return 0;
}
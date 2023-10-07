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
   int x ;
   bool check(TreeNode* root) {
      if (root == nullptr) return true;
      if (root->val != x) return false;
      return check(root->left) && check(root->right);
   }
   bool isUnivalTree(TreeNode* root) {
      x = root->val;
      return check(root);
   }
};

int main() {
   Solution s;


   return 0;
}
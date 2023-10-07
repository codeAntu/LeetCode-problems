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
   TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return root;

      if (key > root->val) {
         root->right = deleteNode(root->right, key);
      } else if (key < root->val) {
         root->left = deleteNode(root->left, key);
      } else {
         if (!root->right) return root->left;
         else if (!root->right) return root->left;
         else {
            TreeNode* cur = root->right;
            while (cur->left) {
               cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteNode(root->right, root->val);
         }
      }
      return root;
   }
};








int main() {
   Solution s;


   return 0;
}
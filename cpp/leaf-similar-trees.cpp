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
   vector<int> leaf1;

   void leafs(TreeNode* root) {
      if (root == nullptr) return;
      if (root->left == nullptr && root->right == nullptr) {
         leaf1.push_back(root->val);
         return;
      }
      leafs(root->left);
      leafs(root->right);
   }

   bool chakeLeaf(TreeNode* root) {
      if (root == nullptr) return true;
      if (root->left == nullptr && root->right == nullptr) {
         if (leaf1.size() == 0) return false;
         if (root->val != leaf1[0]) return false;
         leaf1.erase(leaf1.begin());
         return true;
      }
      return chakeLeaf(root->left) && chakeLeaf(root->right);
   }

   bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      leafs(root1);
      if(chakeLeaf(root2) && leaf1.size() == 0) return true;
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}
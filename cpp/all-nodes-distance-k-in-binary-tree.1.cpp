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
   vector<int> ans;
   void dfs(TreeNode* root, int k) {
      if (root == NULL) {
         return;
      }
      if (k == 0) {
         ans.push_back(root->val);
         return;
      }
      dfs(root->left, k - 1);
      dfs(root->right, k - 1);
   }

   int distance(TreeNode* root, TreeNode* target, int k) {
      if (root == NULL) {
         return -1;
      }
      if (root == target) {
         dfs(root, k);
         return 0;
      }
      int dl = distance(root->left, target, k);
      if (dl != -1) {
         if (dl + 1 == k) {
            ans.push_back(root->val);
         } else {
            dfs(root->right, k - dl - 2);
         }
         return dl + 1;
      }
      int dr = distance(root->right, target, k);
      if (dr != -1) {
         if (dr + 1 == k) {
            ans.push_back(root->val);
         } else {
            dfs(root->left, k - dr - 2);
         }
         return dr + 1;
      }
      return -1;
   }

   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      distance(root, target, k);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

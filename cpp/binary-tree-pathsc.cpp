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
   vector<string> str;
   void dfs(TreeNode* root, string s) {
      if (!root) {
         return;
      }
      if (!root->left && !root->right) {
         str.push_back(s + to_string(root->val));
         return;
      }
      dfs(root->left, s + to_string(root->val) + "->");
      dfs(root->right, s + to_string(root->val) + "->");
   }

   vector<string> binaryTreePaths(TreeNode* root) {
      dfs(root, "");
      return str;
   }
};


int main() {
   Solution s;


   return 0;
}
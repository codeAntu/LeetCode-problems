#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
   string smallestFromLeaf(TreeNode *root) {
      if (!root) return "";
      string s = string(1, 'a' + root->val);
      if (!root->left && !root->right) return s;
      return min(smallestFromLeaf(root->left) + s, smallestFromLeaf(root->right) + s);
   }
};

class Solution {
  public:
   string smallestFromLeaf(TreeNode *root, string s = "") {
      if (!root) return "|";
      s = string(1, 'a' + root->val) + s;
      if (!root->left && !root->right) return s;
      return min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s));
   }
};

int main() {
   Solution s;

   return 0;
}

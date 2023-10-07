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
   vector<int> vec;
   int maxdepth = 0;
   void helper(TreeNode* root, int depth) {
      if (!root) return;
      if (depth > maxdepth) {
         vec.push_back(root->val);
         maxdepth = depth;
      }
      helper(root->right, depth + 1);
      helper(root->left, depth + 1);
   }
   vector<int> rightSideView(TreeNode* root) {
      helper(root, 1);
      return vec;
   }
};

int main() {
   Solution s;


   return 0;
}


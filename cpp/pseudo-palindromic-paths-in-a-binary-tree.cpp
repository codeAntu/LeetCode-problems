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
   int count = 0;
   int result = 0;
   int pseudoPalindromicPaths(TreeNode *root) {
      if (root == nullptr) return 0;
      count ^= (1 << root->val);
      if (root->left) pseudoPalindromicPaths(root->left);
      if (root->right) pseudoPalindromicPaths(root->right);
      if (root->left == nullptr && root->right == nullptr) {
         if ((count & (count - 1)) == 0) result++;
      }
      count ^= (1 << root->val);
      return result;
   }
};

int main() {
   cout << (1 << 4);
   return 0;
}

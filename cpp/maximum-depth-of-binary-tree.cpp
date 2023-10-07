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

// done
class Solution {
public:
   int gratervalue(int m , int n){
      return m > n ? m : n;
   }
   int fun(TreeNode* root, int i) {
      if (root)
      {
         return gratervalue( fun(root->left, i++) , fun(root->right, i++));
      }
      return i;
   }
   int maxDepth(TreeNode* root) {
      return fun(root, 0);
   }
};

int main() {
   Solution s;


   return 0;
}
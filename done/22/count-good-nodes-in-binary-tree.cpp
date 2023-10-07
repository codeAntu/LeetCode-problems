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
   int count = 0;
   void ifGoodNodes(TreeNode* root, int preMax) {
      if (!root) return;
      if (root->val >= preMax) {
         count++;
         preMax = root->val;
      }
      ifGoodNodes(root->left, preMax);
      ifGoodNodes(root->right, preMax);
      return;
   }
   int goodNodes(TreeNode* root) {
      ifGoodNodes(root, root->val);
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}
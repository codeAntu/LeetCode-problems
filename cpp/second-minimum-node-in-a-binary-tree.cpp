#include "iostream"
#include "map"
#include "math.h"
#include "unordered_set"
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
   unordered_set<int> s;
   void visit(TreeNode *root) {
      if (root == NULL) return;
      s.insert(root->val);
      visit(root->left);
      visit(root->right);
   }
   int findSecondMinimumValue(TreeNode *root) {
      if (root == NULL) return -1;
      if (root->left == NULL && root->right == NULL) return -1;
      long smallest = 2147483648;
      long secSmallest = 2147483648;
      visit(root);
      for (int i : s) {
         if (i < smallest) {
            secSmallest = smallest;
            smallest = i;
         } else if (i < secSmallest) {
            secSmallest = i;
         }
      }
      return secSmallest == 2147483648 ? -1 : secSmallest;
   }
};

int main() {
   Solution s;

   return 0;
}

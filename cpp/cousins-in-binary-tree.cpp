#include "iostream"
#include "map"
#include "math.h"
#include "queue"
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
   bool isCousins(TreeNode *root, int x, int y) {
      if (root == NULL) return false;
      queue<TreeNode *> q;
      int a = 0, b = 0;
      q.push(root);
      while (!q.empty()) {
         int n = q.size();
         for (int i = 0; i < n; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL) {
               if (temp->left->val == x) a = temp->val;
               if (temp->left->val == y) b = temp->val;
               q.push(temp->left);
            }
            if (temp->right != NULL) {
               if (temp->right->val == x) a = temp->val;
               if (temp->right->val == y) b = temp->val;
               q.push(temp->right);
            }
            if (a != 0 && b != 0) return a != b;
         }
         a = 0;
         b = 0;
      }
      return false;
   }
};

int main() {
   Solution s;

   return 0;
}

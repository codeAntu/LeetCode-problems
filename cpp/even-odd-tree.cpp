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
   bool isEvenOddTree(TreeNode *root) {
      queue<TreeNode *> q;
      q.push(root);

      int level = 0;

      while (!q.empty()) {
         int size = q.size();
         int prev = level % 2 ? INT_MAX : INT_MIN;
         for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if (level % 2) {
               if (temp->val % 2 || temp->val >= prev) return false;
            } else {
               if (temp->val % 2 == 0 || temp->val <= prev) return false;
            }
            prev = temp->val;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
         }
         level++;
      }
      return true;
   }
};

int main() {
   Solution s;

   return 0;
}

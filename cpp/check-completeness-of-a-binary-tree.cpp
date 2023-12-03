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
   bool isCompleteTree(TreeNode *root) {
      queue<TreeNode *> q;
      q.push(root);
      bool flag = false;

      while (!q.empty()) {
         int size = q.size();
         for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left) {
               if (flag) return false;
               q.push(temp->left);
            } else
               flag = true;
            if (temp->right) {
               if (flag) return false;
               q.push(temp->right);
            } else
               flag = true;
         }
      }
      return true;
   }
};

int main() {
   Solution s;

   return 0;
}

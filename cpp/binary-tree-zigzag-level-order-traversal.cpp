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
   vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
      queue<TreeNode *> q;
      vector<vector<int>> ans;
      if (!root) return ans;
      q.push(root);
      bool flag = false;
      while (!q.empty()) {
         int size = q.size();
         vector<int> temp;
         while (size--) {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
         }
         if (flag) reverse(temp.begin(), temp.end());
         ans.push_back(temp);
         flag = !flag;
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

#include <queue>

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
   vector<int> largestValues(TreeNode *root) {
      vector<int> ans;
      queue<TreeNode *> q;
      if (root) q.push(root);

      while (!q.empty()) {
         int n = q.size();
         int max = INT_MIN;
         for (int i = 0; i < n; i++) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->val > max) max = tmp->val;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
         }
         ans.push_back(max);
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

#include "iostream"
#include "map"
#include "math.h"
#include "queue"
#include "unordered_map"
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
   int getOperations(vector<int> &level) {
      int count = 0;
      vector<int> temp = level;
      unordered_map<int, int> m;
      sort(temp.begin(), temp.end());
      for (int i = 0; i < temp.size(); i++) m[temp[i]] = i;

      for (int i = 0; i < level.size(); i++) {
         if (level[i] != temp[i]) {
            swap(level[i], level[m[level[i]]]);
            count++;
            i--;
         }
      }
      return count;
   }
   int minimumOperations(TreeNode *root) {
      if (root == nullptr) return 0;
      int ans = 0;
      queue<TreeNode *> q;
      q.push(root);

      while (!q.empty()) {
         vector<int> level;
         int size = q.size();
         while (size--) {
            TreeNode *node = q.front();
            level.push_back(node->val);
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
         }
         ans = ans + getOperations(level);
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

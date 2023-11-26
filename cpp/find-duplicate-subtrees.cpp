#include "iostream"
#include "map"
#include "math.h"
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
   unordered_map<string, pair<TreeNode *, int>> m;
   string serialize(TreeNode *root) {
      if (!root) return "";
      string s = "(" + serialize(root->left) + to_string(root->val) + serialize(root->right) + ")";
      if (m.count(s)) {
         m[s].second++;
      } else {
         m[s] = {root, 1};
      }
      return s;
   }
   vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
      vector<TreeNode *> ans;
      serialize(root);
      for (auto it = m.begin(); it != m.end(); it++) {
         if (it->second.second > 1) ans.push_back(it->second.first);
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

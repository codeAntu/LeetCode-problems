#include <cstdarg>
#include <type_traits>
#include <unordered_set>

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
  vector<TreeNode *> res;
  unordered_set<int> del;
  void dfs(TreeNode *&root) {
    if (root == NULL) return;

    dfs(root->left);
    dfs(root->right);

    if (del.find(root->val) != del.end()) {
      if (root->left) res.push_back(root->left);
      if (root->right) res.push_back(root->right);
      root = NULL;
      delete root;
    }
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    for (int i = 0; i < to_delete.size(); i++) {
      del.insert(to_delete[i]);
    }

    dfs(root);
    res.push_back(root);
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}
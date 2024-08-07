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
  vector<TreeNode *> ans;
  void del(TreeNode *root, vector<int> &to_delete) {
    if (root == NULL) return;
    del(root->left, to_delete);
    del(root->right, to_delete);
    for (int i = 0; i < to_delete.size(); i++) {
      if (root->val == to_delete[i]) {
        if (root->left != NULL) ans.push_back(root->left);
        if (root->right != NULL) ans.push_back(root->right);
        root = NULL;
        return;
      }
    }
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    del(root, to_delete);
    if (root != NULL) ans.push_back(root);
    return ans;
  }
};

// class Solution {
// public:
//   vector<TreeNode *> res;
//   unordered_set<int> del;
//   void dfs(TreeNode *&root) {
//     if (root == NULL) return;

//     dfs(root->left);
//     dfs(root->right);

//     if (del.find(root->val) != del.end()) {
//       if (root->left) res.push_back(root->left);
//       if (root->right) res.push_back(root->right);
//       root = NULL;
//       delete root;
//     }
//   }

//   vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
//     for (int i = 0; i < to_delete.size(); i++) {
//       del.insert(to_delete[i]);
//     }

//     dfs(root);
//     if (root) res.push_back(root);
//     return res;
//   }
// };

// class Solution {
//   public:
//    vector<TreeNode *> res;
//    void dfs(TreeNode *&root, vector<int> &to_delete) {
//       if (root == NULL) return;
//       dfs(root->left, to_delete);
//       dfs(root->right, to_delete);
//       if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
//          if (root->left) res.push_back(root->left);
//          if (root->right) res.push_back(root->right);
//          root = NULL;
//          delete root;
//       }
//    }
//    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
//       dfs(root, to_delete);
//       if (root)
//          res.push_back(root);
//       return res;
//    }
// };
int main() {
  Solution s;

  return 0;
}

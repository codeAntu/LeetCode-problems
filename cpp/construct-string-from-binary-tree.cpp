#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  string s;
  string tree2str(TreeNode* root) {
    if (root == nullptr) return "";
    s += to_string(root->val);
    if (root->left != nullptr) {
      s += "(";
      tree2str(root->left);
      s += ")";
    }
    if (root->right != nullptr) {
      if (root->left == nullptr) s += "()";
      s += "(";
      tree2str(root->right);
      s += ")";
    }
    return s;

  }
};

int main() {
  Solution s;


  return 0;
}

#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_set"
using namespace std;



struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//   bool find(TreeNode* root, int k, TreeNode* node) {
//     if (root == nullptr) return false;
//     if (root->val == k && root != node) return true;
//     if (root->val > k) return find(root->left, k, node);
//     return find(root->right, k, node);
//   }

//   bool Target(TreeNode* root, int k, TreeNode* node) {
//     if (node == nullptr) return false;
//     if (find(root, k - node->val, node)) return true;
//     return Target(root, k, node->left) || Target(root, k, node->right);
//   }

//   bool findTarget(TreeNode* root, int k) {
//     return Target(root, k, root);
//   }
// };


class Solution {
public:
  unordered_set<int> s;
  bool findTarget(TreeNode* root, int k) {
    if (root == nullptr) return false;
    if (s.find(k - root->val) != s.end()) return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};


int main() {
  Solution s;


  return 0;
}

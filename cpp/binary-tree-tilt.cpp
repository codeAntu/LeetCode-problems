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
  int res = 0;
  int findTilt(TreeNode* root) {
    Tilt(root);
    return res;
  }
  int Tilt(TreeNode* root) {
    if (root == nullptr) return 0;
    if (!root->left && !root->right) {
      return 0;
    }
    int left = Tilt(root->left);
    int right = Tilt(root->right);
    res = abs(left - right);

    return left + right + root->val;
  }
};
int main() {
  Solution s;


  return 0;
}

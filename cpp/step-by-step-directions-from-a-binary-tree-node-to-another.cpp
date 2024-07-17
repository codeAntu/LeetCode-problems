#include <cmath>
#include <string>

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
  bool getpath(TreeNode *root, int val, string &path) {
    if (root->val == val) {
      return true;
    }

    if (root->left && getpath(root->left, val, path)) {
      path.push_back('L');
    } else if (root->right && getpath(root->right, val, path)) {
      path.push_back('R');
    }

    return !path.empty();
  }

  string getDirections(TreeNode *root, int startValue, int destValue) {
    string startPath, destPath;
    getpath(root, startValue, startPath);
    getpath(root, destValue, destPath);

    while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()) {
      startPath.pop_back();
      destPath.pop_back();
    }

    return string(startPath.size(), 'U') + string(rbegin(destPath), rend(destPath));
  }
};

int main() {
  Solution s;

  return 0;
}
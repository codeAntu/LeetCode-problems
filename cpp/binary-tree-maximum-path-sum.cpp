#include <algorithm>
#include <climits>
#include <cstddef>

#include "math.h"

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
  int maxSum = INT_MIN;

  int dfs(TreeNode *root) {
    if (root == NULL) return 0;

    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));

    if (left < 0) left = 0;
    if (right < 0) right = 0;

    maxSum = max(maxSum, left + right + root->val);

    return max(left, right) + root->val;
  }

  int maxPathSum(TreeNode *root) {
    if (root == NULL) return 0;
    dfs(root);
    return maxSum;
  }
};

int main() {
  Solution s;

  return 0;
}
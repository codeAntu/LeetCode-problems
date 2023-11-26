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
   int count = 0;
   vector<int> dfs(TreeNode *root, int distance) {
      if (root == nullptr) return {};
      if (root->left == nullptr && root->right == nullptr) return {1};
      vector<int> left = dfs(root->left, distance);
      vector<int> right = dfs(root->right, distance);
      for (int i = 0; i < left.size(); i++) {
         for (int j = 0; j < right.size(); j++) {
            if (left[i] + right[j] <= distance) count++;
         }
      }
      vector<int> res;
      for (int i = 0; i < left.size(); i++) {
         if (left[i] + 1 < distance) res.push_back(left[i] + 1);
      }
      for (int i = 0; i < right.size(); i++) {
         if (right[i] + 1 < distance) res.push_back(right[i] + 1);
      }
      return res;
   }
   int countPairs(TreeNode *root, int distance) {
      dfs(root, distance);
      return count;
   }
};

int main() {
   Solution s;

   return 0;
}

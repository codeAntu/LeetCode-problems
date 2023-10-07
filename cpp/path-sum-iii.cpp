#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_map"
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
   unordered_map <long, int> m;
   int count = 0;
   void dfs(TreeNode* root, int targetSum, long sum) {
      if (!root) return;
      sum += root->val;
      if (sum == targetSum) count++;

      if (m.find(sum - targetSum) != m.end()) {
         count += m[ sum - targetSum];
      }
      m[sum]++;
      dfs(root->left, targetSum, sum);
      dfs(root->right, targetSum, sum);
      m[sum]--;
   }
   int pathSum(TreeNode* root, int targetSum) {
      dfs(root,targetSum , 0);

      return count;
   }
};

int main() {
   Solution s;


   return 0;
}
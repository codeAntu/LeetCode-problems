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
   unordered_map<int, int> m;
   int max = 0;
   int dfs(TreeNode *root) {
      if (!root) return 0;
      int sum = root->val + dfs(root->left) + dfs(root->right);
      m[sum]++;
      if (m[sum] > max) max = m[sum];
      return sum;
   }
   vector<int> findFrequentTreeSum(TreeNode *root) {
      vector<int> ans;
      dfs(root);
      for (auto i : m) {
         if (i.second == max) {
            ans.push_back(i.first);
         }
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}

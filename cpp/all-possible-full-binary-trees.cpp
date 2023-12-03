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
   unordered_map<int, vector<TreeNode *>> dp;

   vector<TreeNode *> build(int n) {
      if (dp.find(n) != dp.end()) return dp[n];
      vector<TreeNode *> ans;
      if (n == 1) {
         ans.push_back(new TreeNode(0));
         return ans;
      }

      for (int i = 1; i <= n; i += 2) {
         vector<TreeNode *> left = build(i);
         vector<TreeNode *> right = build(n - i - 1);

         for (auto l : left) {
            for (auto r : right) {
               TreeNode *root = new TreeNode(0, l, r);
               ans.push_back(root);
            }
         }
      }
      dp[n] = ans;
      return ans;
   }

   vector<TreeNode *> allPossibleFBT(int n) {
      return build(n);
   }
};

int main() {
   Solution s;

   return 0;
}

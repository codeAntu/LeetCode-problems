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
   vector<TreeNode *> build(int start, int end) {
      vector<TreeNode *> ans;
      if (start > end) {
         ans.push_back(nullptr);
         return ans;
      }
      for (int i = start; i <= end; i++) {
         vector<TreeNode *> left = build(start, i - 1);
         vector<TreeNode *> right = build(i + 1, end);

         for (auto l : left) {
            for (auto r : right) {
               TreeNode *root = new TreeNode(i, l, r);
               ans.push_back(root);
            }
         }
      }
      return ans;
   }
   vector<TreeNode *> generateTrees(int n) {
      return build(1, n);
   }
};

int main() {
   Solution s;

   return 0;
}

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
   vector<int> ans;
   void visit(TreeNode *root) {
      if (root == NULL) return;
      visit(root->left);
      ans.push_back(root->val);
      visit(root->right);
   }
   void marge(vector<int> &a, vector<int> &b) {
      int i = 0, j = 0;
      vector<int> res;
      while (i < a.size() && j < b.size()) {
         if (a[i] < b[j]) {
            res.push_back(a[i++]);
         } else {
            res.push_back(b[j++]);
         }
      }
      while (i < a.size()) {
         res.push_back(a[i++]);
      }
      while (j < b.size()) {
         res.push_back(b[j++]);
      }
      ans = res;
   }

   vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
      visit(root1);
      int n = ans.size();
      visit(root2);
      return ans;
   }
};

// class Solution {
//   public:
//    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
//       vector<int> result;
//       inorder(root1, result);
//       auto size = result.size();
//       inorder(root2, result);
//       inplace_merge(result.begin(), result.begin() + size, result.end());
//       return result;
//    }
//    void inorder(TreeNode *node, vector<int> &vec) {
//       if (!node)
//          return;
//       inorder(node->left, vec);
//       vec.push_back(node->val);
//       inorder(node->right, vec);
//    }
// };

int main() {
   Solution s;

   return 0;
}

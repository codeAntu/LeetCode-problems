#include <set>

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

class FindElements {
  public:
   set<int> s;
   void dfs(TreeNode *root) {
      if (root == nullptr) return;
      s.insert(root->val);
      if (root->left) {
         root->left->val = 2 * root->val + 1;
         dfs(root->left);
      }
      if (root->right) {
         root->right->val = 2 * root->val + 2;
         dfs(root->right);
      }
   }
   FindElements(TreeNode *root) {
      if (root == nullptr) return;
      root->val = 0;
      s.insert(root->val);
      dfs(root);
   }

   bool find(int target) {
      if (s.find(target) != s.end()) return true;
      return false;
   }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
   return 0;
}

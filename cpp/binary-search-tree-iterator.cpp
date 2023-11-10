#include "iostream"
#include "map"
#include "math.h"
#include "stack"
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

class BSTIterator {
  public:
   stack<TreeNode *> st;
   BSTIterator(TreeNode *root) {
      insert(root);
   }
   void insert(TreeNode *root) {
      while (root) {
         st.push(root);
         root = root->left;
      }
   }
   int next() {
      TreeNode *root = st.top();
      st.pop();
      insert(root->right);
      return root->val;
   }
   bool hasNext() {
      return !st.empty();
   }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
   return 0;
}

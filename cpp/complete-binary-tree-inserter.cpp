#include "iostream"
#include "map"
#include "math.h"
#include "queue"
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

class CBTInserter {
  public:
   TreeNode *tree = nullptr;
   queue<TreeNode *> q;
   CBTInserter(TreeNode *root) {
      tree = root;
      if (root) q.push(root);

      while (!q.empty()) {
         TreeNode *temp = q.front();
         if (temp->left && temp->right) {
            q.push(temp->left);
            q.push(temp->right);
            q.pop();
         } else if (temp->left) {
            q.push(temp->left);
            break;
         } else {
            break;
         }
      }
   }

   int insert(int val) {
      TreeNode *temp = q.front();
      if (temp->left) {
         temp->right = new TreeNode(val);
         q.push(temp->right);
         q.pop();
      } else {
         temp->left = new TreeNode(val);
         q.push(temp->left);
      }
      return temp->val;
   }

   TreeNode *get_root() {
      return tree;
   }
};

int main() {
   return 0;
}

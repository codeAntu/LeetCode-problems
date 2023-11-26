#include <queue>

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
   TreeNode *addOneRow(TreeNode *root, int val, int depth, bool isLeft = true) {
      if (depth == 1) {
         TreeNode *newRoot = new TreeNode(val);
         if (isLeft)
            newRoot->left = root;
         else
            newRoot->right = root;
         return newRoot;
      }
      if (root) {
         root->left = addOneRow(root->left, val, depth - 1);
         root->right = addOneRow(root->right, val, depth - 1, false);
      }
      return root;
   }
};

class Solution {
  public:
   TreeNode *addOneRow(TreeNode *root, int val, int depth) {
      if (depth == 1) {
         TreeNode *newRoot = new TreeNode(val);
         newRoot->left = root;
         return newRoot;
      }
      queue<TreeNode *> q;
      int level = 1;
      q.push(root);

      while (level <= depth - 1) {
         int size = q.size();
         while (size--) {
            TreeNode *curr = q.front();
            q.pop();
            if (level == depth - 1) {
               TreeNode *left = new TreeNode(val);
               TreeNode *right = new TreeNode(val);
               left->left = curr->left;
               right->right = curr->right;
               curr->left = left;
               curr->right = right;
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
         }
         level++;
      }
      return root;
   }
};

class Solution {
  public:
   TreeNode *addOneRow(TreeNode *root, int val, int depth) {
      if (depth == 1) {
         TreeNode *newRoot = new TreeNode(val);
         newRoot->left = root;
         return newRoot;
      }
      queue<pair<TreeNode *, int>> q;
      q.push({root, 1});

      while (!q.empty()) {
         TreeNode *curr = q.front().first;
         int level = q.front().second;
         q.pop();
         if (level == depth - 1) {
            TreeNode *left = new TreeNode(val);
            TreeNode *right = new TreeNode(val);
            left->left = curr->left;
            right->right = curr->right;
            curr->left = left;
            curr->right = right;
         }
         if (curr->left) q.push({curr->left, level + 1});
         if (curr->right) q.push({curr->right, level + 1});
      }
      return root;
   }
};

int main() {
   return 0;
}

#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"queue"
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
   int maxLevelSum(TreeNode* root) {
      if (!root) return 0;
      queue<TreeNode* > q;
      int maxSum = root->val, ans = 1, level = 0;
      q.push(root);
      while (q.size()) {
         level++;
         int n = q.size();
         int sum = 0;
         while (n--) {
            TreeNode* temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
         }
         if (sum > maxSum) {
            maxSum = sum;
            ans = level;
         }
      }
      return ans;
   }
};


class Solution {
public:
   vector<int> vec;
   void helper(TreeNode* root, int depth) {
      if (!root) return;
      vec[depth - 1] += root->val;
      if (root->left) helper(root->left, depth + 1);
      if (root->right) helper(root->right, depth + 1);
   }

   int maxLevelSum(TreeNode* root) {
      if (!root) return 0;
      helper(root, 1);
      int n = vec.size();
      int maxSum = 0, ind = 0;
      for (int i = 0; i < n; i++) {
         if (vec[i] > maxSum) {
            maxSum = vec[i];
            ind = i;
         }
      }
      return ind + 1;
   }
};


class Solution {
public:
   std::vector<int> vec;

   void helper(TreeNode* root, int depth) {
      if (!root) return;
      if (vec.size() < depth) {
         vec.resize(depth);
      }
      vec[depth - 1] += root->val;
      if (root->left) helper(root->left, depth + 1);
      if (root->right) helper(root->right, depth + 1);
   }

   int maxLevelSum(TreeNode* root) {
      if (!root) return 0;
      helper(root, 1);
      int maxSum = vec[0];
      int ind = 0;
      for (int i = 1; i < vec.size(); i++) {
         if (vec[i] > maxSum) {
            maxSum = vec[i];
            ind = i;
         }
      }
      return ind + 1;
   }
};






























int main() {
   Solution s;


   return 0;
}
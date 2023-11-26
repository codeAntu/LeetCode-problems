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
   int sum = 0;
   int temp = 0;

   int sumNumbers(TreeNode *root) {
      if (root == nullptr) return 0;
      temp = temp * 10 + root->val;
      if (root->left == nullptr && root->right == nullptr) {
         sum += temp;
      }
      sumNumbers(root->left);
      sumNumbers(root->right);
      temp /= 10;
      return sum;
   }
};

class Solution {
  public:
   void calSum(TreeNode *root, int &sum, int temp) {
      if (root == nullptr) return;
      temp = temp * 10 + root->val;
      if (root->left == nullptr && root->right == nullptr) sum += temp;
      calSum(root->left, sum, temp);
      calSum(root->right, sum, temp);
   }
   int sumNumbers(TreeNode *root) {
      int sum = 0;
      int temp = 0;
      calSum(root, sum, temp);
      return sum;
   }
};

int main() {
   Solution s;

   return 0;
}

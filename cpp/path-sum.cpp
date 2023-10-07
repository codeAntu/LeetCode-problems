#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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
   bool fun(TreeNode * root , int sum ,int target){
      if(root){
         sum += root-> val;
         if(root->left || root->right) return fun(root-> left, sum , target) || fun(root-> right ,sum, target);
         if (sum == target) return true;
         
      }
      return false;
   }
   bool hasPathSum(TreeNode* root, int targetSum) {
      return fun(root , 0 ,targetSum);
   }
};

int main() {
   Solution s;


   return 0;
}
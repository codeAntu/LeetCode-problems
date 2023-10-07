#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      if (original == target) return cloned;
      if (original->left) cloned->left = getTargetCopy(original->left, cloned->left, target);
      if (original->right) cloned->right = getTargetCopy(original->right, cloned->right, target);
      if (cloned->left) return cloned->left;
      else return cloned->right;
   }
};

int main() {
   Solution s;


   return 0;
}
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

// class Solution {
//   public:
//    int max = 0;
//    map<int, int> m;
//    void visit(TreeNode *root) {
//       if (root == NULL) return;
//       m[root->val]++;
//       max = max > m[root->val] ? max : m[root->val];
//       visit(root->left);
//       visit(root->right);
//    }
//    vector<int> findMode(TreeNode *root) {
//       visit(root);
//       vector<int> res;

//       for (auto &i : m) {
//          if (i.second == max) {
//             res.push_back(i.first);
//          }
//       }
//       return res;
//    }
// };

class Solution {
  public:
   int max = 0;
   int last = INT_MAX;
   int count = 0;
   vector<int> res;

   void traverse(TreeNode *root) {
      if (root == NULL) return;

      traverse(root->left);
      if (root->val == last) {
         count++;
      } else {
         count = 1;
         last = root->val;
      }

      if (count == max) {
         res.push_back(root->val);
      } else if (count > max) {
         max = count;
         res.clear();
         res.push_back(root->val);
      }
      traverse(root->right);
   }

   vector<int>
   findMode(TreeNode *root) {
      traverse(root);
      return res;
   }
};

int main() {
   Solution s;

   return 0;
}

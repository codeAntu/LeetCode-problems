#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
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
   vector<double> averageOfLevels(TreeNode* root) {
      int count;
      double sum;
      vector<double> ans;
      queue<TreeNode*> q;
      q.push(root);
      while (q.size()) {
         sum = 0;
         count = q.size();

         for (int i = 0; i < count; i++) {
            sum += q.front()->val;
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
         }
         ans.push_back((double)sum / count);
      }
      return ans;
   }
};


int main() {
   Solution s;


   return 0;
}
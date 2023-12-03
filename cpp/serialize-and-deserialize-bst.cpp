#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  public:
   // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
      if (root == nullptr) return "N";
      return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
   }

   // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
      vector<string> v;
      string temp = "";
      for (int i = 0; i < data.size(); i++) {
         if (data[i] == ',') {
            v.push_back(temp);
            temp = "";
         } else {
            temp += data[i];
         }
      }
      int index = 0;
      return build(v, index);
   }

   TreeNode* build(vector<string>& data, int& index) {
      if (index >= data.size()) return nullptr;
      if (data[index] == "N") return nullptr;
      TreeNode* root = new TreeNode(stoi(data[index]));
      root->left = build(data, ++index);
      root->right = build(data, ++index);
      return root;
   }
};

TreeNode* ans = nullptr;
class Codec {
  public:
   // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
      ans = root;
      return "";
   }

   // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
      return ans;
   }
};

int main() {
   return 0;
}

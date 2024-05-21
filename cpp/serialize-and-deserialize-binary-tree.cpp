#include <queue>
#include <string>

#include "math.h"
#include "vector"

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Codec {
// public:
//   string res = "";

//   void dfs(TreeNode *root) {
//     if (root == NULL) {
//       res += "null,";
//       return;
//     }

//     res += to_string(root->val) + ",";
//     dfs(root->left);
//     dfs(root->right);
//   }

//   // Encodes a tree to a single string.
//   string serialize(TreeNode *root) {
//     dfs(root);
//     return res;
//   }

//   TreeNode *deserializeHelper(vector<string> &nodes, int &index) {
//     if (nodes[index] == "null") {
//       index++;
//       return NULL;
//     }

//     TreeNode *node = new TreeNode(stoi(nodes[index]));
//     index++;
//     node->left = deserializeHelper(nodes, index);
//     node->right = deserializeHelper(nodes, index);

//     return node;
//   }

//   // Decodes your encoded data to tree.
//   TreeNode *deserialize(string data) {
//     vector<string> nodes;
//     string node = "";
//     for (int i = 0; i < data.size(); i++) {
//       if (data[i] == ',') {
//         nodes.push_back(node);
//         node = "";
//       } else {
//         node += data[i];
//       }
//     }

//     int index = 0;
//     return deserializeHelper(nodes, index);

//   }
// };

// NOW USING BFS

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node == NULL) {
        res += "null,";
        continue;
      }

      res += to_string(node->val) + ",";
      q.push(node->left);
      q.push(node->right);
    }

    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> nodes;
    string node = "";
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == ',') {
        nodes.push_back(node);
        node = "";
      } else {
        node += data[i];
      }
    }

    if (nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (nodes[i] != "null") {
        node->left = new TreeNode(stoi(nodes[i]));
        q.push(node->left);
      }
      i++;

      if (nodes[i] != "null") {
        node->right = new TreeNode(stoi(nodes[i]));
        q.push(node->right);
      }
      i++;
    }

    return root;
  }
};

int main() { return 0; }
#include <algorithm>

#include "iostream"
#include "map"
#include "math.h"
#include "unordered_map"
#include "unordered_set"
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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    int n = descriptions.size();
    if (n == 0) return nullptr;
    TreeNode *nodes[100001] = {nullptr};
    unordered_set<int> isparent;

    for (int i = 0; i < n; i++) {
      int parent = descriptions[i][0];
      int child = descriptions[i][1];
      int isLeft = descriptions[i][2];

      if (nodes[parent] == nullptr) nodes[parent] = new TreeNode(parent);
      if (nodes[child] == nullptr) nodes[child] = new TreeNode(child);

      if (isLeft == 1)
        nodes[parent]->left = nodes[child];
      else
        nodes[parent]->right = nodes[child];

      isparent.insert(child);
    }

    for (int i = 0; i < n; i++) {
      if (isparent.find(descriptions[i][0]) == isparent.end()) {
        return nodes[descriptions[i][0]];
      }
    }

    return nullptr;
  }
};

// class Solution {
// public:
//   TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
//     int n = descriptions.size();
//     if (n == 0) return nullptr;
//     unordered_map<int, TreeNode *> map;
//     unordered_set<TreeNode *> set;

//     for (int i = 0; i < n; i++) {
//       int per = descriptions[i][0];
//       int child = descriptions[i][1];
//       int isLeft = descriptions[i][2];

//       if (map.find(per) == map.end()) map[per] = new TreeNode(per);

//       if (map.find(child) == map.end()) map[child] = new TreeNode(child);

//       if (isLeft == 1)
//         map[per]->left = map[child];
//       else
//         map[per]->right = map[child];

//       set.insert(map[child]);
//     }

//     for (auto &it : map) {
//       if (set.find(it.second) == set.end()) {
//         return it.second;
//       }
//     }

//     return nullptr;
//   }
// };

// class Solution {
//   public:
//    TreeNode *create(unordered_map<int, pair<int, int>> &map, int root) {
//       if (root == 0) return nullptr;
//       TreeNode *node = new TreeNode(root);
//       if (map.find(root) == map.end()) return node;
//       node->left = create(map, map[root].first);
//       node->right = create(map, map[root].second);
//       return node;
//    }
//    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
//       unordered_map<int, pair<int, int>> map;
//       unordered_set<int> set;
//       int root = 0;

//       for (auto &description : descriptions) {
//          if (map.find(description[0]) == map.end()) map[description[0]] = make_pair(0, 0);
//          if (description[2] == 1) {
//             map[description[0]].first = description[1];
//          } else {
//             map[description[0]].second = description[1];
//          }
//          set.insert(description[1]);
//       }
//       for (auto &description : descriptions) {
//          if (set.find(description[0]) == set.end()) {
//             root = description[0];
//             break;
//          }
//       }

//       return create(map, root);
//    }
// };

int main() {
  Solution s;

  return 0;
}

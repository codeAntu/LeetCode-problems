#include <unordered_map>

#include "math.h"
#include "vector"

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
    if (m.find(node) != m.end()) return m[node];

    Node* newNode = new Node(node->val);
    m[node] = newNode;

    for (auto n : node->neighbors) {
      newNode->neighbors.push_back(dfs(n, m));
    }
    return newNode;
  }

  Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    unordered_map<Node*, Node*> m;

    return dfs(node, m);
  }
};

int main() {
  Solution s;

  return 0;
}
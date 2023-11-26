#include <queue>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Node {
  public:
   int val;
   Node* left;
   Node* right;
   Node* next;

   Node() : val(0), left(NULL), right(NULL), next(NULL) {}

   Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

   Node(int _val, Node* _left, Node* _right, Node* _next)
       : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
   Node* connect(Node* root) {
      if (root == nullptr) return nullptr;
      queue<Node*> q;
      q.push(root);

      while (!q.empty()) {
         int size = q.size();
         Node* prev = nullptr;
         for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (prev != nullptr) prev->next = curr;
            prev = curr;
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
         }
      }
      return root;
   }
};

int main() {
   Solution s;

   return 0;
}

#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    Node* newHead = new Node(0);
    Node* newHeadPtr = newHead;
    Node* headPtr = head;
    map<Node*, Node*> nodeMap;
    while (headPtr) {
      Node* newNode = new Node(headPtr->val);
      newHeadPtr->next = newNode;
      nodeMap[headPtr] = newNode;
      newHeadPtr = newHeadPtr->next;
      headPtr = headPtr->next;
    }
    headPtr = head;
    newHeadPtr = newHead->next;
    while (headPtr) {
      newHeadPtr->random = nodeMap[headPtr->random];
      headPtr = headPtr->next;
      newHeadPtr = newHeadPtr->next;
    }
    return newHead->next;
  }
};

// class Solution {
// private:
//   unordered_map<Node*, Node*> map;

// public:
//   Node* copyRandomList(Node* head) {
//     if (head == nullptr) return nullptr;
//     if (auto it = map.find(head); it != map.cend()) return map[head];

//     Node* newNode = new Node(head->val);
//     map[head] = newNode;
//     newNode->next = copyRandomList(head->next);
//     newNode->random = copyRandomList(head->random);
//     return newNode;
//   }
// };

int main() {
  Solution s;

  return 0;
}
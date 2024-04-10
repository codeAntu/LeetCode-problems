#include <stack>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    stack<ListNode *> s;
    ListNode *cur = head;
    while (cur) {
      s.push(cur);
      cur = cur->next;
    }

    int n = s.size();
    cur = head;
    for (int i = 0; i < n / 2; i++) {
      ListNode *next = cur->next;
      cur->next = s.top();
      s.pop();
      cur->next->next = next;
      cur = next;
    }
    cur->next = nullptr;
  }
};

int main() {
  Solution s;

  return 0;
}
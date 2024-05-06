#include <stack>
#include "math.h"

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
  ListNode *removeNodes(ListNode *head) {
    stack<ListNode *> s;
    ListNode *temp = new ListNode(INT_MAX);
    ListNode *ans = temp;
    temp->next = head;
    while (temp) {
      while (!s.empty() && temp->val > s.top()->val) {
        s.pop();
      }
      if (!s.empty()) {
        s.top()->next = temp;
      }
      s.push(temp);
      temp = temp->next;
    }

    return ans->next;
  }
};

int main() {
  Solution s;

  return 0;
}
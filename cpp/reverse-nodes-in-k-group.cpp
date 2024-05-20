#include <utility>
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
  pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *p = head;
    while (prev != tail) {
      ListNode *next = p->next;
      p->next = prev;
      prev = p;
      p = next;
    }
    return {tail, head};
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;

    while (head) {
      ListNode *tail = prev;
      for (int i = 0; i < k; i++) {
        tail = tail->next;
        if (!tail) return dummy->next;
      }

      ListNode *next = tail->next;
      pair<ListNode *, ListNode *> result = reverse(head, tail);
      head = result.first;
      tail = result.second;

      prev->next = head;
      tail->next = next;
      prev = tail;
      head = tail->next;
    }

    return dummy->next;
  }
};

int main() {
  Solution s;

  return 0;
}
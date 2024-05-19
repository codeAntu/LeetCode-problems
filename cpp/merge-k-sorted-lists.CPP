#include "math.h"
#include "vector"

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* mergeList(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    while (l1 != nullptr) {
      cur->next = l1;
      l1 = l1->next;
      cur = cur->next;
    }

    while (l2 != nullptr) {
      cur->next = l2;
      l2 = l2->next;
      cur = cur->next;
    }

    return dummy->next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;

    while (lists.size() != 1) {
      vector<ListNode*> newLists;

      for (int i = 0; i < lists.size(); i += 2) {
        if (i == lists.size() - 1) {
          newLists.push_back(lists[i]);
        } else {
          newLists.push_back(mergeList(lists[i], lists[i + 1]));
        }
      }

      lists = newLists;
    }

    return lists[0];
  }
};

int main() {
  Solution s;

  return 0;
}
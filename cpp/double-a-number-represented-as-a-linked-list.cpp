#include "math.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// class Solution {
// public:
//   ListNode* doubleIt(ListNode* head) {
//     stack<int> s;
//     ListNode* current = head;
//     while (current != nullptr) {
//       s.push(current->val);
//       current = current->next;
//     }

//     ListNode* Current = nullptr;
//     int carry = 0;
//     while (!s.empty()) {
//       int val = s.top() * 2 + carry;
//       carry = val / 10;
//       val = val % 10;
//       s.pop();

//       ListNode* newCurrent = new ListNode(val);
//       newCurrent->next = Current;
//       Current = newCurrent;
//     }
//     if(carry > 0) {
//       ListNode* newCurrent = new ListNode(carry);
//       newCurrent->next = Current;
//       Current = newCurrent;
//     }
//     return Current;
//   }
// };

class Solution {
public:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
      ListNode* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
  ListNode* doubleIt(ListNode* head) {
    head = reverse(head);
    ListNode* current = head;
    int carry = 0;
    while (current != nullptr) {
      int val = current->val * 2 + carry;
      carry = val / 10;
      val = val % 10;
      current->val = val;

      if (current->next == nullptr && carry > 0) {
        ListNode* newCurrent = new ListNode(carry);
        current->next = newCurrent;
        break;
      }
      current = current->next;
    }

    ListNode* result = reverse(head);
    return result;
  }
};

int main() {
  Solution s;

  return 0;
}
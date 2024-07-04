#include <cstdarg>

#include "iostream"
#include "map"
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
  ListNode* mergeNodes(ListNode* head) {
    ListNode* ans = head->next;
    while (ans) {
      ListNode* temp = ans;
      int sum = 0;
      while (temp->val != 0) {
        sum += temp->val;
        temp = temp->next;
      }
      ans->val = sum;
      ans->next = temp->next;
      ans = ans->next;
    }
    return head->next;
  }
};

int main() {
  Solution s;

  return 0;
}
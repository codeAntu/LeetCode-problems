#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "stack"
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
   bool isPalindrome(ListNode* head) {
      ListNode* slow = head, * fast = head;
      stack<int> s;
      while (fast && fast->next) {
         s.push(slow->val);
         slow = slow->next;
         fast = fast->next->next;
      }

      if (fast) {
         slow = slow->next;
      }

      while (slow) {
         if (s.top() != slow->val) {
            return false;
         }
         s.pop();
         slow = slow->next;
      }

      return true;

   }
};



int main() {
   Solution s;


   return 0;
}
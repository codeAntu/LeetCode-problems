#include "iostream"
#include "math.h"
#include "vector"
#include "map"
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
   ListNode* reverseList(ListNode* head) {
      if (head) {
         ListNode* temp1, * temp2;
         temp1 = NULL;
         while (head->next)
         {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
         }
         head->next = temp1;
         return head;
      }
      return NULL;
   }

   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


      if (!l1 && !l2) return NULL;
      int sum = 0, carry = 0;
      l1 = reverseList(l1);
      l2 = reverseList(l2);
      ListNode* ans;
      ListNode* head = new ListNode();
      ans = head;
      while (l1 || l2) {
         sum = carry;
         if (l1) {
            sum += l1->val;
            l1 = l1->next;
         }
         if (l2) {
            sum += l2->val;
            l2 = l2->next;
         }
         ListNode* num = new ListNode(sum % 10);
         head->next = num;
         head = head->next;
         carry = sum / 10;
      }
      if (carry) {
         ListNode* num = new ListNode(carry);
         head->next = num;
      }
      ans->next = reverseList(ans->next);
      return ans->next;
   }
};

int main() {
   Solution s;


   return 0;
}
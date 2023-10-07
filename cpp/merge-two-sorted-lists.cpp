#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done


struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};


struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
      ListNode head,*temp = &head;

      head.next = NULL;
      while (list1 && list2)
      {
         if (list1->val > list2->val)
         {
            temp->next = list2;
            list2 = list2->next;
         } else
         {
            temp->next = list1;
            list1 = list1->next;
         }
         temp = temp ->next;
      }
      if (list1)
         temp->next = list1;
      else
         temp->next = list2;

      return head.next;

   }

};

int main() {
   Solution s;


   return 0;
}
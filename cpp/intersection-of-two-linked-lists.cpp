#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

// done
class Solution {
public:
   ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      ListNode* l1 = headA, * l2 = headB;

      while (l1 != l2)
      {
         if (l1 == NULL) l1 = headB;
         else l1 = l1->next;
         if (l2 == NULL) l2 = headA;
         else l2 = l2->next;

      }
      return l1;
   }
};

int main() {
   Solution s;


   return 0;
}
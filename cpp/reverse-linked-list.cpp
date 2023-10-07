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
};

int main() {
   Solution s;


   return 0;
}
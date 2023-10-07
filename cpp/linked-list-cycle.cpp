#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   bool hasCycle(ListNode* head) {
      if (!head)
         return false;
      ListNode* fast = head;
      ListNode* slow = head;
      while (fast && fast->next)
      {
         fast = fast->next->next;
         slow = slow->next;
         if (fast == slow) return true;
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}
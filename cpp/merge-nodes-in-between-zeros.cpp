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
   ListNode* mergeNodes(ListNode* head) {
      ListNode* ans = head->next;
      int sum = 0;
      while (ans) {
         sum = 0;
         ListNode* it = ans;
         while (it->val != 0) {
            sum += it->val;
            it = it->next;
         }
         ans->val = sum;
         ans->next = it->next;
         ans = ans->next;
      }
      return head ->next;
   }
};

int main() {
   Solution s;


   return 0;
}
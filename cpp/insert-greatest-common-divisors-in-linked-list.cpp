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
   int gcd(int a, int b) {
      if (b == 0) return a;
      return gcd(b, a % b);
   }
   ListNode* insertGreatestCommonDivisors(ListNode* head) {
      ListNode* ans = head;
      while (head && head->next) {
         ListNode* node = new ListNode(gcd(head->val, head->next->val));
         node->next = head->next;
         head->next = node;
         head = head->next->next;
      }
      return ans;
   }
};


int main() {
   Solution s;

   cout << s.gcd(10, 9) << endl;

   return 0;
}
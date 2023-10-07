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
   int pairSum(ListNode* head) {

      int count = 0, i = 0;
      ListNode* curr = head;

      while (curr != NULL) {
         count++;
         curr = curr->next;
      }
      count = count / 2;
      vector<int> v(count, 0);
      for (int i = 0; i < count; i++) {
         v[i] = head->val;
         head = head->next;
      }
      for (int i = 0; i < count; i++) {
         v[count - 1 - i] += head->val;
         head = head->next;
      }
      int res = 0;
      for (int i = 0; i < count; i++) {
         res = max(res, v[i]);
      }

      return res;
   }
};

int main() {
   Solution s;


   return 0;
}
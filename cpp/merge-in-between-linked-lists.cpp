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
   ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode* curr = list1, * temp;
      int i = 0;
      for (i = 0; i < a - 1;i++) {
         curr = curr->next;
      }
      temp = curr;
      for (i; i <= b;i++) {
         temp = temp->next;
      }
      curr->next = list2;
      while (curr->next){
         curr = curr->next;
      }
      curr->next = temp;
      return list1;
   }
};

int main() {
   Solution s;


   return 0;
}
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

class Solution {
public:
   void deleteNode(ListNode* node) {
      ListNode* temp = node->next;
      *node = *temp;
      delete temp;
   }
};


int main() {
   Solution s;


   return 0;
}
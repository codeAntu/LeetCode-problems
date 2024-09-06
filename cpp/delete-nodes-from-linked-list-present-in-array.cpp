#include <unordered_set>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s;
    ListNode* dummy = new ListNode(0);
    for (int i = 0; i < nums.size(); i++) {
      s.insert(nums[i]);
    }

    dummy->next = head;

    ListNode* prev = dummy;

    while (head) {
      if (s.find(head->val) != s.end()) {
        prev->next = head->next;
      } else {
        prev = head;
      }
      head = head->next;
    }

    return dummy->next;
  }
};

int main() {
  Solution s;

  return 0;
}
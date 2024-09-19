#include "math.h"
#include "vector"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int length = 0;
    vector<ListNode *> arr(k);
    ListNode *curr = head;
    ListNode *temp = head;
    int div = 0;
    int rem = 0;

    while (curr) {
      curr = curr->next;
    }

    curr = head;

    div = length / k;
    rem = length % k;

    for (int i = 0; i < k; i++) {
      int currSize = div;
      if (rem > 0) {
        rem--;
        currSize++;
      }

      temp = curr;
      arr[i] = temp;

      for (int j = 0; j < currSize; j++) {
        if (curr) {
          curr = curr->next;
          temp = temp->next;
        }
      }

      if (temp != nullptr) {
        temp->next = nullptr;
      }
    }

    return arr;
  }
};

int main() {
  Solution s;

  return 0;
}